#include "SimpleButton.h"


SimpleButton knop (22);
SimpleButton knop1(23);
SimpleButton knop2(24);
SimpleButton knop3(25);
SimpleButton knop4(26);
byte knopStatus    = 0;
int counter1       = 0;

void setup() {
  knop .begin();
  knop1.begin();
  knop2.begin();  
  knop3.begin(); 
  knop4.begin();     
  Serial.begin(9600);
}

void loop() {

knopStatus =  knop.longShortPress(3000); 
if (knopStatus != 0)
  { Serial.println (knopStatus); 
  }

if (knop2.pulsed(4000))     
  { counter1++;
    Serial.println(counter1);
  }

if (knop3.toggleUp() == true)
  {if (knop1.flankUp())
     { Serial.println("flankUp knop1");
     }
  }
else
  {if (knop1.flankDn())
    { Serial.println("flankDn knop1");
    }
  }
  
if (knop4.timedOn(1000)) 
  {Serial.println("TimedOn");
  }
  }
