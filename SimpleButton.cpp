//
//  SimpleButton.cpp
//  
//
//  Created by Davy Pelckmans on 4/10/19.
//
//

#include "SimpleButton.h"
#include <Arduino.h>

SimpleButton::SimpleButton(uint8_t pin)
: _pin(pin)
, _counter1(0)
, _pushed  (false)
, countAmount(500)
, _counter2(0)
, _flankUpPulse (false)
, _flankDnPulse (false)
, _toggledUp(false)
, _toggledDn(false)
, _snapShot (0)
, _snapped (false)
, _timed (false)
{}


// Initialising pinmode

void SimpleButton::begin() {
    pinMode(_pin, INPUT_PULLUP);
}


// Reading and debouncing the input

bool SimpleButton::read()
{   if (!digitalRead(_pin) == true)
    { _pushed = true; _counter1 = 0;
    }
    if (_pushed == true)
    { _counter1++;
    }
    if (_counter1 == countAmount)
    { _pushed = false;
    }
    return _pushed;
}


// Creating a one cycle pulse when button is pressed

bool SimpleButton::flankUp()
{   read();
    if ((_pushed == true) && (_counter2 < 3))
    { _counter2++;
    }
    if (_counter2 == 1)
    { _flankUpPulse = true;
    }
    else
    { _flankUpPulse = false;
    }
    if (flankDn())
    { _counter2 = 0;
    }
    return _flankUpPulse;
}


// Creating a one cycle pulse when button is released

bool SimpleButton::flankDn()
{   read();
    if (_counter1 == countAmount-1)
    { _flankDnPulse = true;
    }
    else
    { _flankDnPulse = false;
    }
    return _flankDnPulse;
}


// Creating a one cycle pulse on pressed, and released

bool SimpleButton::flankUpDn()
{   read();
    if ((_pushed == true) && (_counter2 < 3))
    { _counter2++;
    }
    if (_counter2 == 1)
    { _flankUpPulse = true;
    }
    else
    { _flankUpPulse = false;
    }
    if (_counter1 == countAmount-1)
    { _flankDnPulse = true;
      _counter2 = 0;
    }
    else
    { _flankDnPulse = false;
    }
    return _flankUpPulse || _flankDnPulse;
}


// Toggle a switch when pressed

bool SimpleButton::toggleUp()
{   if (flankUp())
    { _toggledUp = !_toggledUp;
    }
    return _toggledUp;
}


// Toggle a switch when released

bool SimpleButton::toggleDn()
{   if (flankDn())
    { _toggledDn = !_toggledDn;
    }
    return _toggledDn;
}



// Sets a single cycle pulse after the given time
// When pressed during this time, timer reset

bool SimpleButton::timedOn(int time)
{   if (flankUp())
    {   _snapShot = millis();
        _snapped = true;
    }
    if ((millis() - _snapShot > time) && (_snapped == true))
    {   _snapped = false;
        return true;
    }
    return false;
}



// Returns 1 for a single cycle, if pressed and released, returns 2 for a single cycle;
// if pressed and hold for the given time.

byte SimpleButton::longShortPress(int time)
{   flankUp();
    if (_flankUpPulse == true)
    {   _snapShot = millis();
        _snapped = true;
    }
    if ((millis() - _snapShot > time) && (_snapped == true))
    {   _snapped = false;
        return 1;
    }
    if ((_pushed == false) && (_snapped == true))
    {   _counter2++;
        if (_counter2 == 1)
        {   _counter2 = 0;
            _snapped = false;
            return 2;
        }
    }
    return 0;
}


// As long as button is pressed, there will be a 1 cycle pulse generated each
// "pulseSpeed" cycles of counter 2

bool SimpleButton::pulsed(int pulseSpeed)
{   read();
    if (_pushed == true)
    {   _counter2++;
        if (_counter2 == 1)
        {   return true;
        }
        if (_counter2 == pulseSpeed)
        {   _counter2 = 0;
        }
    }
    if (_pushed == false)
    {   _counter2 = 0;
    }
    return false;
}

    
    
        
