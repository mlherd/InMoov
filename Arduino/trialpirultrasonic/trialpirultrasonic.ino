#define MAX_DISTANCE 400   // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define ECHOPIN 3              // Echo Pin of the ultrasonic sensor
#define TRIGPIN 2           // Trigger pin ofthe ultrasonic sensor
int pirPin = 4;              // PIR sensor Pin
//int distance = 0;          // Default distance measured by ultrasonic sensor
// the time when the sensor outputs a low impulse
long unsigned int lowIn;
// the amount of milliseconds the sensor has to be low
// before we assume all motion has stopped
long unsigned int pause = 2000;
boolean lockLow = true;
boolean takeLowTime;
int calibrationTime = 11;


void setup() {
  
  Serial.begin(9600);
  //pinMode(pirPin, INPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  //calibratePir();
}

////////////////////////////
//LOOP
void loop(){
  //readPIR();      // Call the function to Read the PIR  sensor
  pingDist();        // Call the function to measure distance from th ultrasonic sensor if motion is detected 
}
void calibratePir(){
  digitalWrite(pirPin, LOW);
   // give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
  for (int i = 0; i < calibrationTime; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
}
//////////////////
//PIR Function
void readPIR() {
  if (digitalRead(pirPin) == HIGH) {
    if (lockLow) {
      //makes sure we wait for a transition to LOW before any further output is made:
      lockLow = false;
      Serial.println("---");
      Serial.print("motion detected at ");
      Serial.print(millis() / 1000);
      Serial.println(" sec");
      delay(50);
    }
    takeLowTime = true;
  }

  if (digitalRead(pirPin) == LOW) {
    if (takeLowTime) {
      lowIn = millis();          //save the time of the transition from high to LOW
      takeLowTime = false;       //make sure this is only done at the start of a LOW phase
    }
    //if the sensor is low for more than the given pause,
    //we assume that no more motion is going to happen
    if (!lockLow && millis() - lowIn > pause) {
      //makes sure this block of code is only executed again after
      //a new motion sequence has been detected
      lockLow = true;
      Serial.print("motion ended at ");      //output
      Serial.print((millis() - pause) / 1000);
      Serial.println(" sec");
      delay(50);
    }
  }
}
//////////////
// Ultrasonic sensor distance reading
void pingDist () {
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance= distance/58;                        // Calculate distance from time of pulse
  Serial.println(distance);                     
  delay(50);                                // Wait 50mS before next ranging
}

