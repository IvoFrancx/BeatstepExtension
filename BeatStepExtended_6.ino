#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

MIDI_CREATE_DEFAULT_INSTANCE();

float k1;  //KNOB 1
float k2;  //KNOB 2
float k3;  //KNOB 3
boolean s1;  //SWITCH 1
boolean s2;  //SWITCH 2


////////////////////////////////////////////////////////////////////////////SETUP

void setup() {
  for (int i=2; i<14; i++) {
    pinMode(i, OUTPUT);
  }
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandleClock(handleClock);
  MIDI.setHandleStart(handleStart);
  MIDI.setHandleStop(handleStop);
  MIDI.setHandleContinue(handleContinue);
  randomSeed(analogRead(A7));
  startupAnimation();
}

void loop() {
  MIDI.read();
  readVoltages();
}


