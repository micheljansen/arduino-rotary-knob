/*
 * Knob.h 
 * Models an incremental rotary encoder knob.
 *
 * The current implementation models a 12-step quadrature encoder
 * that outputs 2-bit gray code, like the 318-ENC130175F-12PS 
 * (Ref.#: TW-700198) sold by SparkFun Electronics.
 *
 * Usage: run setup(pinA, pinB) in the Arduino setup() method. 
 * Then: run read() from within the loop().
 *
 * Copyright (c) 2010 Michel Jansen
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
#ifndef KNOB_H
#define KNOB_H

class Knob {
  public:
    /**
     * Setup the Knob using the given pins.
     * This must be called once, before the first read()
     * and is used for late initialisation
     * so we can have an empty default constructor.
     * */
    void setup(int pinA, int pinB);

    /**
     * Read new state from pins.
     * @return 0 if no change, -1 if prev, +1 if next
     */
    int read();

    inline int getCount() const { return count; }
    inline int getPinA() const { return pinA; }
    inline int getPinB() const { return pinA; }
    
  private:
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
