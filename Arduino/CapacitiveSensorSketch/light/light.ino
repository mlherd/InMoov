int temt6000Pin = 0;
int ledGreenPin = 3;
void setup() {
  Serial.begin(9600);
  pinMode(ledGreenPin, OUTPUT);
}

void loop() {
  int value = analogRead(temt6000Pin);
  



  // map it to the range of the analog out:
  value = map(value, 0, 1023, 0, 255);
  // change the analog out value:
  Serial.println(value);
  analogWrite(ledGreenPin, value);
  delay(100); //only here to slow down the output so it is easier to read
}
