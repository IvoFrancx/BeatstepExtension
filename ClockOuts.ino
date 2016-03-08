void ClockOuts(int clck) {

  ////////Output 12 || Viertel ticks
  if (clck % 24 == 0) digitalWrite(13, HIGH);        ////Led an bei 4teln
  else if (clck % 24 == 3)digitalWrite(13, LOW);     ////Led aus nach 3/32tel

  ///////Output 11 || Clicks with Clock Divider
  if (clck%int(24.0*ckDiv) == 0) digitalWrite(12, HIGH);        ////Led an bei 4teln
  else if (clck%int(24.0*ckDiv) == 3)digitalWrite(12, LOW);     ////Led aus nach 3/32tel

  ////Random ticks (16ths)
  int rndm2 = (int)random(0,2);
  if (clck % 6 == 0) {
    if (rndm2 == 1) digitalWrite(11,HIGH);
  }
  else if (clck % 6 == 3) {
    if (rndm2 == 0) digitalWrite(11,LOW);
  }
}
