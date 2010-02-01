/**
 * QuadEncoder.cpp - Library for reading moves from a quadratic rotary encoder
 * Created by Pedro Rodrigues (medecau@gmail.com) 9, January of 2010
 * Modified by Andreas Lekas (spadusa@gmail.com) 31, January, 2010
 * Released into the public domain.
 */

#include "WProgram.h"
#include "QuadEncoder.h"

QuadEncoder::QuadEncoder(int pin1, int pin2, int pin3)
{
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  _moved = false;
  _inputPin1=pin1;
  _inputPin2=pin2;
  _inputPin3=pin3;
  _val1=1;
  _val2=1;
  _oldVal1=1;
  _oldVal2=1;
  _pos=0;
  _oldPos=0;
  _turn=0;
  _turnCount=0;
}

char QuadEncoder::readEncoder()
{  
  _moved = false;
  _val1 = digitalRead(_inputPin1);
  _val2 = digitalRead(_inputPin2);
    // Detect changes
  if ( _val1 != _oldVal1 || _val2 != _oldVal2) {
    _oldVal1=_val1;
    _oldVal2=_val2;
    
      //for each pair there's a position out of four
    if ( _val1 == 1 ) {// stationary position
      if (_val2 == 1)
        _pos = 0;
      else if (_val2 == 0)
        _pos = 3;
    } else if (_val1 == 0){
      if (_val2 == 1)
        _pos = 1;
      else if (_val2 == 0)
        _pos = 2;
    }
    
    _turn = _pos-_oldPos;
    _oldPos = _pos;
    if (abs(_turn) != 2) {
      if (_turn == 1 || _turn == -3)
        _turnCount++;
      else if (_turn == -1 || _turn == 3)
        _turnCount--;
    }
    if (_pos==0){
      if (_turnCount>0){
        _turnCount=0;
		_moved = true;
        return '>';
      } else if (_turnCount<0){
		_moved = true;
        _turnCount=0;
        return '<';
      } else {
		_moved = false;
        _turnCount=0;
        return '-';
      }
    }
  }
}
bool QuadEncoder::didMove()
{
	return _moved;
}

bool QuadEncoder::pressed()
{
	return digitalRead(_inputPin3)==0;
}