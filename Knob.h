/*
 * Knob.h
 * Models a rotary encoder knob
 */
 
#ifndef KNOB_H
#define KNOB_H

class Knob {
  public:
    void setup(int pinA, int pinB);

    /**
     * Read new state from pins.
     * @return 0 if no change, -1 if prev, +1 if next
     */
    int read();
    
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
