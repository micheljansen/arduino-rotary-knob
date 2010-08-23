/*
 * Knob.h
 * Models a rotary encoder knob
 */
 
#ifndef KNOB_H
#define KNOB_H

class Knob {
  public:
    void setup(int pinA, int pinB);

    void read();
    
    int pinA;
    int pinB;
    int state;
    int prevState;
    int count;
    int cycleCount;

    static const int cw[];                           
    static const int ccw[];    
};



#endif
