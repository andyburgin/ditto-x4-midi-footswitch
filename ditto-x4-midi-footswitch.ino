// ----------------------------------------------------------------------------
// Ditto x4 midi footswitch
// 
// Button one press = stop loop 1
// Button one long press = clear loop 1
// Button two press = stop loop 2
// Button two long press = clear loop 2
//
// Libraries used:
// - OneButton ( https://github.com/mathertel/OneButton/tree/1.5.0 )
// ----------------------------------------------------------------------------
#include <Arduino.h>
#include <MIDI.h>
#include <OneButton.h>

// Buttons
#define PIN_BUTTON_ONE (A1)
#define PIN_BUTTON_TWO (A2)
OneButton _btnOne(PIN_BUTTON_ONE, true);
OneButton _btnTwo(PIN_BUTTON_TWO, true);

// main
void setup() {
  Serial.begin(115200);
  Serial.print(F("Running "));
  
  // button init
  _btnOne.attachClick(onOnePushed);
  _btnOne.attachLongPressStart(onOneLongPush);
  
  _btnTwo.attachClick(onTwoPushed);
  _btnTwo.attachLongPressStart(onTwoLongPush);
}

void loop() {
  _btnOne.tick();
  _btnTwo.tick();
}


// buttons
void onOnePushed() {
  Serial.print(F("onOnePushed"));
}

void onTwoPushed() {
  Serial.print(F("onTwoPushed"));
}

void onOneLongPush() {
  Serial.print(F("onOneLongPush "));
}
  
void onTwoLongPush() {
  Serial.print(F("onTwoLongPush "));
}
