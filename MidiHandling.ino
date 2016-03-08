////////////////////////////////////////////////////////////////////////////NOTE ON
void handleNoteOn(byte inChannel, byte inNote, byte inVelocity) {
  MIDI.sendNoteOn(inNote, inVelocity, inChannel); //to repllicate the input (thru)
  if (inVelocity > 0 && inChannel == 10) {
    if      (inNote == 44) digitalWrite(2 , HIGH);
    else if (inNote == 45) digitalWrite(3 , HIGH);
    else if (inNote == 46) digitalWrite(4 , HIGH);
    else if (inNote == 47) digitalWrite(5 , HIGH);
    else if (inNote == 48) digitalWrite(6 , HIGH); 
    else if (inNote == 49) digitalWrite(7 , HIGH);
    else if (inNote == 50) digitalWrite(8 , HIGH);
    else if (inNote == 51) digitalWrite(9 , HIGH);
  }
}

////////////////////////////////////////////////////////////////////////////NOTE OFF
void handleNoteOff(byte inChannel, byte inNote, byte inVelocity) {
  MIDI.sendNoteOff(inNote, inVelocity, inChannel);  //to repllicate the input (thru)
  if (inChannel == 10) { 
    if      (inNote == 44) digitalWrite(2 , LOW);
    else if (inNote == 45) digitalWrite(3 , LOW);
    else if (inNote == 46) digitalWrite(4 , LOW);
    else if (inNote == 47) digitalWrite(5 , LOW);
    else if (inNote == 48) digitalWrite(6 , LOW); 
    else if (inNote == 49) digitalWrite(7 , LOW);
    else if (inNote == 50) digitalWrite(8 , LOW);
    else if (inNote == 51) digitalWrite(9 , LOW);
  }
}

////////////////////////////////////////////////////////////////////////////START & STOP
boolean playFlag;

void handleStart() {
  playFlag = true;
  clck = 0;
}

void handleStop() {
  playFlag = false;
  for (int i=2; i<14; i++) {
    digitalWrite(i,LOW);
  }
}

void handleContinue() {
  playFlag = true;
}


