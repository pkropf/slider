// Copyright (c) 2013 Peter Kropf. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <Servo.h> 

Servo sol1;                // servo 1
int   sol1pin = 3;         // servo 1 control pin

Servo sol2;                // servo 2
int   sol2pin = 5;         // servo 2 control pin

int   pot1pin = 4;         // potentiometer 1
int   pot1val = 0;

int   pot2pin = 6;         // potentiometer 2
int   pot2val = 0;


// Common servo setup values
int minPulse = 600;   // minimum servo position, us (microseconds)
int maxPulse = 2400;  // maximum servo position, us

// User input for servo and position


void setup() 
{
  Serial.begin(57600);

  sol1.attach(sol1pin, minPulse, maxPulse);
  sol2.attach(sol2pin, minPulse, maxPulse);
}


void loop()
{
  pot1val = analogRead(pot1pin);
  sol1.write(map(pot1val, 0, 1023, minPulse, maxPulse));

  pot2val = analogRead(pot2pin);
  sol2.write(map(pot2val, 0, 1023, minPulse, maxPulse));
}

