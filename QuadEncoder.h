/**
 * QuadEncoder.h - Library for reading moves from a quadratic rotary encoder
 * Created by Pedro Rodrigues (medecau@gmail.com) 9, January of 2010
 * Released into the public domain.
 */

#ifndef QuadEncoder_h
#define QuadEncoder_h

#include "WProgram.h"


class QuadEncoder
{
  public:	//pin 1=A, pin2=B, pin3=Shaft button
    QuadEncoder(int pin1, int pin2, int pin3);
    char readEncoder();
	bool pressed();
	bool didMove();
  private:
	bool _moved;
    int _inputPin1;
    int _inputPin2;
    int _inputPin3;
    int _val1;
    int _val2;
    int _oldVal1;
    int _oldVal2;
    int _pos;
    int _oldPos;
    int _turn;
    int _turnCount;  
  };

#endif