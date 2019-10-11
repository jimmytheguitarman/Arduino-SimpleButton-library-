//
//  SimpleButton.h
//  
//
//  Created by Davy Pelckmans on 4/10/19.
//
//

#ifndef Simple_Button_h
#define Simple_Button_h

#include <Arduino.h>

class SimpleButton
{
public:
    SimpleButton(uint8_t pin);
    void begin();
    bool read();
    bool flankUp();
    bool flankDn();
    bool flankUpDn();
    bool toggleUp();
    bool toggleDn();
    bool timedOn(int time);
    byte longShortPress(int time);
    bool pulsed(int pulseSpeed);
    int countAmount;
    
private:
    uint8_t _pin;
    int     _counter1;
    bool    _pushed;
    int     _counter2;
    bool    _flankUpPulse;
    bool    _flankDnPulse;
    bool    _toggledUp;
    bool    _toggledDn;
    long    _snapShot;
    bool    _snapped;
    bool    _timed;
};

#endif /* defined(SimpleButton) */
