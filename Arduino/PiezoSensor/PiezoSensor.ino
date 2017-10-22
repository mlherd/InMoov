int vib_in = 8;
int vib_in2 = 9;
int led = 12;
int led2 = 13;

void setup(){
  Serial.begin(9600);
  pinMode(vib_in, INPUT);
  pinMode(vib_in2, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop(){
        Serial.println("SENSOR 1:");
        Serial.println(digitalRead(vib_in));
        Serial.println("SENSOR 2:");
        Serial.println(digitalRead(vib_in2));
    if(digitalRead(vib_in) == HIGH || digitalRead(vib_in2) == HIGH ){
      //digitalWrite(BUZZER_DIGITAL_OUT_PIN, HIGH);
      //delay(buzzerDurationMillis);
      if(digitalRead(vib_in) == HIGH && digitalRead(vib_in2) == HIGH){
        digitalWrite(led2, HIGH);
        digitalWrite(led, HIGH);
        }
        if(digitalRead(vib_in) == HIGH){ 
        digitalWrite(led, HIGH);
        }
      if(digitalRead(vib_in2) == HIGH){
        digitalWrite(led2, HIGH);
        }
      delay(200);
      
    }
    else{
      digitalWrite(led, LOW);
      digitalWrite(led2, LOW);
      }
}

 void send_data(){
      sensor_datapackage = String(e1) + ":" + String(e2) + ":" + String(e3) + ":" + String(e4) + ":" + String(e5) + ":" + String(e6) + ":" + String(e7) + ":" + String(e8) + ":" + String(e9) + ":" + String(e10) + ":" + String(e11) + ":" + String(e12) + ":";
      Serial.println(sensor_datapackage);
      }
