////////////////////////////////////////////////////////////////////////////CLOCK
int clck;
float ckDiv = 1;
boolean rhythmArray[96];

void handleClock() {
    
  if (clck == 96) clck = 0;    //////////////////////////Reset nach einem Takt
  
  ClockOuts(clck);

  /////RANDOM OUT 1:
  if      ( s1) readRhythmArray ();
  else if (!s1) writeRhythmArray();
  
  /////////////////////////////////////////////////////////////////////////WICHTIGSTER TEIL DER CLOCK
  clck++;                      ////Allgemeinte Clock (96 ticks)
}


boolean pulseDeterminator() {      /////nimmt Werte von 0 bis 1024 /// B: 0 bis 12
  ///k1 bestimmt die allgemeine warscheinlichkeit
  ///k2 bestimmt die Zentrierung auf 4tel (0 = nur 4tel, 1023 = alles gleich warscheinlich)
  float randA = random(0,1024);
  float randB = random(0,12);
  setCkDiv(k3);
  if (randA <= k1 &&  int(((clck%int(24.0*ckDiv))*(k2/1024.0))/ckDiv) <= random(0,12*ckDiv)) return true;   ///  (clck%24)*(k2/1024.0)
  else return false;
}

void readRhythmArray() {
  if (rhythmArray[clck]) digitalWrite(10,HIGH);
  else if (!rhythmArray[clck]) digitalWrite(10,LOW);
}

void writeRhythmArray() {
  if (pulseDeterminator()) {
    digitalWrite(10,HIGH);
    rhythmArray[clck] = true;
  }
  else {
    digitalWrite(10,LOW);
    rhythmArray[clck] = false;
  }
}

///// Clock Divider (At Knob 3)
void setCkDiv(float knob) {
  if (knob < 200) ckDiv = 4;
  else if (knob >= 200 && knob < 400)  ckDiv = 2;
  else if (knob >= 400 && knob < 600) ckDiv = 1;
  else if (knob >= 600 && knob < 800) ckDiv = 0.5;
  else if (knob >= 800) ckDiv = 0.25;
}

