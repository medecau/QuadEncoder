/**
 * QuadEncoder.h - Library for reading moves from a quadrature rotary encoder
 * Created by Pedro Rodrigues (medecau@gmail.com) 9, January of 2010
 * Released into the public domain.
 */

#ifndef QuadEncoder_h
#define QuadEncoder_h

#include "WProgram.h"


class QuadEncoder
{
  public:
    QuadEncoder(int pin1, int pin2);
    char hb();
  private:
    int _inputPin1;
    int _inputPin2;
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