// ----------------------------------------------------------------------------
// Ditto x4 midi footswitch
// 
// Button one press = stop loop 1
// Button one long press = clear loop 1
// Button two press = store loop 1
// Button two long press = clear stored loop 1
// Button three press = store loop 2
// Button three long press = clear stored loop 2
// Button four press = stop loop 2
// Button four long press = clear loop 2
//
// Libraries used:
// - Arduino MIDI Library ( https://github.com/FortySevenEffects/arduino_midi_library/releases/tag/5.0.2 )
// - OneButton ( https://github.com/mathertel/OneButton/tree/1.5.0 )
// ----------------------------------------------------------------------------
#include <Arduino.h>
#include <MIDI.h>
#include <OneButton.h>

// Buttons
#define PIN_BUTTON_ONE (A1)
#define PIN_BUTTON_TWO (A3)
#define PIN_BUTTON_THREE (A4)
#define PIN_BUTTON_FOUR (A2)
OneButton _btnOne(PIN_BUTTON_ONE, true);
OneButton _btnTwo(PIN_BUTTON_TWO, true);
OneButton _btnThree(PIN_BUTTON_THREE, true);
OneButton _btnFour(PIN_BUTTON_FOUR, true);

// Midi
#define DITTO_CHANNEL 4
#define CC_LOOPER_ONE_STOP 9
#define CC_LOOPER_ONE_CLEAR 14
#define CC_LOOPER_ONE_STORE 20
#define CC_LOOPER_ONE_CLEAR_STORE 21
#define CC_LOOPER_TWO_STOP 23
#define CC_LOOPER_TWO_CLEAR 24
#define CC_LOOPER_TWO_STORE 26
#define CC_LOOPER_TWO_CLEAR_STORE 27

#define CC_MIDI_ON 127

MIDI_CREATE_DEFAULT_INSTANCE();

// main
void setup() {
  Serial.begin(115200);
  Serial.print(F("Running "));

  MIDI.begin(MIDI_CHANNEL_OMNI);
  
  // button init
  _btnOne.attachClick(onOnePushed);
  _btnOne.attachLongPressStart(onOneLongPush);
  
  _btnTwo.attachClick(onTwoPushed);
  _btnTwo.attachLongPressStart(onTwoLongPush);

  _btnThree.attachClick(onThreePushed);
  _btnThree.attachLongPressStart(onThreeLongPush);

  _btnFour.attachClick(onFourPushed);
  _btnFour.attachLongPressStart(onFourLongPush);
}

void loop() {
  MIDI.read();
  _btnOne.tick();
  _btnTwo.tick();
  _btnThree.tick();
  _btnFour.tick();
}


// buttons
void onOnePushed() {
  Serial.print(F("onOnePushed"));
  MIDI.sendControlChange(CC_LOOPER_ONE_STORE,CC_MIDI_ON,DITTO_CHANNEL);
}

void onTwoPushed() {
  Serial.print(F("onTwoPushed"));
  MIDI.sendControlChange(CC_LOOPER_ONE_STOP,CC_MIDI_ON,DITTO_CHANNEL);
}

void onThreePushed() {
  Serial.print(F("onThreePushed"));
  MIDI.sendControlChange(CC_LOOPER_TWO_STOP,CC_MIDI_ON,DITTO_CHANNEL);
}

void onFourPushed() {
  Serial.print(F("onFourPushed"));
  MIDI.sendControlChange(CC_LOOPER_TWO_STORE,CC_MIDI_ON,DITTO_CHANNEL);
}

void onOneLongPush() {
  Serial.print(F("onOneLongPush "));
  MIDI.sendControlChange(CC_LOOPER_ONE_CLEAR_STORE,CC_MIDI_ON,DITTO_CHANNEL);
}
  
void onTwoLongPush() {
  Serial.print(F("onTwoLongPush "));
  MIDI.sendControlChange(CC_LOOPER_ONE_CLEAR,CC_MIDI_ON,DITTO_CHANNEL);
}

void onThreeLongPush() {
  Serial.print(F("onThreeLongPush "));
  MIDI.sendControlChange(CC_LOOPER_TWO_CLEAR,CC_MIDI_ON,DITTO_CHANNEL);
}
  
void onFourLongPush() {
  Serial.print(F("onFourLongPush "));
  MIDI.sendControlChange(CC_LOOPER_TWO_CLEAR_STORE,CC_MIDI_ON,DITTO_CHANNEL);
}
