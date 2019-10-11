# Arduino-SimpleButton-library-
A simple library i've wrote to handle and debounce input switches on the Arduino platform.

## Functions

The "begin" command sets the input pin in INPUT_PULLUP mode, so no resistor needs to be added.

"read"  is the main debounce command. It works with a counter to debounce. You can also set the
 debounce length with countAmount.

"flankUp" is used to create a single cycle pulse on when pushed.

"flankDn" is the opposite of flankUp. It creates a single cycle pulse on release.

"flankUpDn" creates a single cycle pulse on pushed, and on release.

"toggleUp" toggles the button state on pushed.

"toggleDn" toggles the button state on release.

"timedOn(int time)" gives a one cycle pulse after the button is pushed (pulsed, or hold).
If pulsed, and pulsed in the waiting time, the time is reset.

"longShortPress(int time)" Outputs a byte. 0 = off, 1 = timed, and 2 = released before timed.
If you keep pressing the button, the output will become 1 for a single cycle. If you release the$
button before the time has been reached, the output will become 2 for a single cycle.

"pulsed(int pulseSpeed)" This function outputs a pulse of x pulseSpeed as long as you press the 
button. This can be handy for scrolling functions.

