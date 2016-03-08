////////////////////////////////////////////////////////////////////////////READ KNOBS & SWITCHES

void readVoltages() {
  k1 = analogRead(A0);  //// Knob 1 (General frequency of occurrence)
  k2 = analogRead(A1);  //// Knob 2 (Frequency of occurrence near Clock Div setting)
  k3 = analogRead(A2);  //// Knob 3 (Clock divider setting (1/2, 1/4, 1/16, 1/32)
  if      (analogRead(A3)>= 512) s1 = true;      ///Switch 1 (Store/Read last Bar)
  else if (analogRead(A3)<  512) s1 = false;
  if      (analogRead(A4)>= 512) s2 = true;      ///Switch 2 (
  else if (analogRead(A4)<  512) s2 = false;
}
