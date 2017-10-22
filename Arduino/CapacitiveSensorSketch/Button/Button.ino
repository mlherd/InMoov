/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonDown = 52;// the number of the pushbutton pin
const int buttonUp = 51;
const int buttonLeft = 50;
const int buttonRight = 49;
const int buttonCenter = 48;
const int buttonSelect = 47;
const int buttonStart = 46;
const int buttonA = 45;
const int buttonB = 44;
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonStateUp = 0;         // variable for reading the pushbutton status
int buttonStateDown = 0;
int buttonStateLeft = 0;
int buttonStateRight = 0;
int buttonStateCenter = 0;
int buttonStateSelect = 0;
int buttonStateStart = 0;
int buttonStateA = 0;
int buttonStateB = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonDown, INPUT);
  pinMode(buttonUp, INPUT);
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(buttonSelect, INPUT);
  pinMode(buttonStart, INPUT);
  pinMode(buttonCenter, INPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateUp = digitalRead(buttonUp);
  buttonStateDown = digitalRead(buttonDown);
  buttonStateLeft = digitalRead(buttonLeft);
  buttonStateRight = digitalRead(buttonRight);
  buttonStateSelect = digitalRead(buttonSelect);
  buttonStateStart = digitalRead(buttonStart);
  buttonStateCenter = digitalRead(buttonCenter);
  buttonStateA = digitalRead(buttonA);
  buttonStateB = digitalRead(buttonB);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonStateUp == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonStateDown == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonStateLeft == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonStateRight == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonStateSelect == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonStateStart == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonStateCenter == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  
  if (buttonStateA == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if (buttonStateB == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
