int animationDelay = 30;

void startupAnimation() {
    for (int rotationDelay=animationDelay;rotationDelay>0;rotationDelay--) {
    for (int i=2;i<13;i+=2) {
      digitalWrite(i,HIGH);
      digitalWrite(15-i,HIGH);
      delay(rotationDelay);
      digitalWrite(i,LOW);
      digitalWrite(15-i,LOW);
    }
  }
}
