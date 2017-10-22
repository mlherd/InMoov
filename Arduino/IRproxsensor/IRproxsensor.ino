int sensorPin = 0; //analog pin 0

void setup(){
  Serial.begin(9600);
}

void loop(){
  int val = analogRead(sensorPin);
  Serial.println(val);

  if(val >390) {
    Serial.println("too close");
  }else{
    Serial.println("That's more like it");
  }

  //just to slow down the output - remove if trying to catch an object passing by
  delay(100);

}
