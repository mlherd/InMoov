#define VIBRATION_DIGITAL_IN_PIN 8
#define VIBRATION_DIGITAL_IN_PIN2 9
#define LED 12
#define LED2 13

void setup(){
  pinMode(VIBRATION_DIGITAL_IN_PIN, INPUT);
   pinMode(VIBRATION_DIGITAL_IN_PIN2, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop(){
    if(digitalRead(VIBRATION_DIGITAL_IN_PIN) == HIGH || digitalRead(VIBRATION_DIGITAL_IN_PIN2) == HIGH){
      if(digitalRead(VIBRATION_DIGITAL_IN_PIN) == HIGH){
        digitalWrite(LED, HIGH);
      }
      if (digitalRead(VIBRATION_DIGITAL_IN_PIN2) == HIGH){
        digitalWrite(LED2, HIGH);
        }
     delay(1000);
    }
    else {
        digitalWrite(LED, LOW);
        digitalWrite(LED2, LOW);
    }
}
