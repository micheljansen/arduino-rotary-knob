#include "WProgram.h"
#include "Knob.h"


const int Knob::cw[4] = {
			  2, // 10 -> 11
			  0, // 00 -> 10
			  3, // 11 -> 01
			  1  // 01 -> 00
			};

const int Knob::ccw[4] = {
			  1, // 01 -> 11
			  3, // 11 -> 10
			  0, // 00 -> 01
			  2  // 10 -> 00
			};

void Knob::setup(int pinA, int pinB) {
  this->pinA = pinA;
  this->pinB = pinB;

  pinMode(this->pinA, INPUT);
  pinMode(this->pinB, INPUT);

  digitalWrite(this->pinA, HIGH);
  digitalWrite(this->pinB, HIGH);

  this->state = 0;
  this->prevState = 0;
  this->count = 0;
  this->cycleCount = 0;
}

void Knob::read() {
  byte a = digitalRead(this->pinA);
  byte b = digitalRead(this->pinB);
  this->state = (a << 1 | b);
  
  if (state != prevState) {
	if(state == cw[prevState]) {
	  // going forward
	  cycleCount++;
	}
	else if(state == ccw[prevState]) {
	  // going backward
	  cycleCount--;
	}
	
	if(state == 3) {
	  if(cycleCount > 0) {
		count++;
		Serial.print(count);
		Serial.println(" PLUS");
	  }
	  else if(cycleCount < 0) {
		count--;
		Serial.print(count);
		Serial.println(" MINUS");
	  }
	  else {
//        Serial.print(count);
//        Serial.println(" UNKNOWN");
	  }
	  cycleCount = 0;
	}
	
	prevState = state;
  }
}


