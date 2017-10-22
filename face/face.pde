import processing.serial.*;                //USB Serial Comm. Library
// Serial Port Variables
Serial port;   
String serial_value   = "0";               //Variable for the data comes from Arduino
String[] list;
// Sensor Values
int[] electrode_values = new int[13];;
int touch_sensor      = 0;                 // list[0]    
int vibration_sensor1 = 0;                 // list[1]
int vibration_sensor2 = 0;                 // list[2]
int vibration_sensor3 = 0;                 // list[3]
int vibration_sensor4 = 0;                 // list[4]
int light_sensor1     = 0;                 // list[5]
int light_sensor2     = 0;                 // list[6]
int gesture_sensor    = 0;                 // list[7]
int temp_sensor1      = 0;                 // list[8]
int temp_sensor2      = 0;                 // list[9]
int temp_sensor3      = 0;                 // list[10]
int sound_sensor1     = 0;                 // list[11]
int sound_sensor2     = 0;                 // list[12]
//Colors
color red = color(255, 0, 0);
color white = color(255,255,255);
color blue = color(0, 0, 255);
color green = color(0, 255, 0);
// Setup Function
void setup() {
  port = new Serial(this,"COM8",115200);    //Serial port setup
  port.bufferUntil('\n'); 
  size(640, 480);
  background(255);
}

void draw() {
 fill(white);
 ellipseMode(CENTER);
 //FRONT OF HEAD
 ellipse(160,240,280,440);                                     //FACE
 painter(7);
 arc(300, 240, 60, 100, radians(96),radians(264));             //LEFT EAR
 painter(6);
 arc(21, 240, 60, 100, radians(-81),radians(81));              //RIGHT EAR
 fill(white);
 ellipse(115, 180 , 50, 30);                                   //RIGHT EYE
 ellipse(210, 180, 50, 30);                                    //LEFT EYE
 triangle(150, 225, 160, 255, 170, 225);                       //NOSE
 arc(160, 340, 100, 40 ,radians(0),radians(180));              //MOUTH
 
 stroke(255);                                                  //PEN COLOR IS WHITE 
 painter(5);
 ellipse(110, 260 , 45, 80);                                   //LEFT CHEEK
 painter(4);
 ellipse(210, 260, 45, 80);                                    //RIGTH CHEEK
 painter(8);
 ellipse(160, 420, 80, 30);                                    //CHIN
 stroke(0);                                                    //PEN COLOR IS BLACK
 
 //ARCS IN FRONT OF HEAD
 painter(1);
 arc(160, 160, 260, 280, radians(180), radians(225));          //FRONT ARC 1
 painter(2);
 arc(160, 160, 260, 280, radians(225), radians(270));          //FRONT ARC 2
 painter(2);
 arc(160, 160, 260, 280, radians(-90), radians(-45));          //FRONT ARC 3
 painter(3);
 arc(160, 160, 260, 280, radians(-45), radians(0));            //FRONT ARC 4

 
 //BACK OF HEAD
 arc (480, 240, 280, 440, radians(-180), radians(0), CHORD);   //BACK OF HEAD - UPPER PART
 rectMode(CENTER); 
 fill(white);
 rect(480, 330, 70, 60);                                       //NECK
 painter(12);
 rect(480, 270, 280, 60);                                      //BACK OF HEAD - BOTTOM PART
 
 //ARCS IN BACK OF HEAD
 painter(9);
 arc(480, 240, 280, 440, radians(180), radians(225));          //BACK ARC 1
 painter(11);
 arc(480, 240, 280, 440, radians(225), radians(270));          //BACK ARC 2
 painter(11);
 arc(480, 240, 280, 440, radians(-90), radians(-45));          //BACK ARC 3
 painter(10);
 arc(480, 240, 280, 440, radians(-45), radians(0));            //BACK ARC 4                                              
 //
}
 // Painter
 void painter(int spot_number){
 if(electrode_values[spot_number]  == 1){
 fill(red);
 }
 else{
 fill(white);
 }
 }
 // SERIAL EVENT - READ
 void serialEvent (Serial port){                               // Serial Event - Read Function
 serial_value = port.readStringUntil('\n');
 list = split(serial_value, ":");
 electrode_values[1]      = int(list[0]);                 // list[0]
 electrode_values[2]      = int(list[1]);                 // list[1]
 electrode_values[3]      = int(list[2]);                 // list[2]
 electrode_values[4]      = int(list[3]);                 // list[3]
 electrode_values[5]      = int(list[4]);                 // list[4]
 electrode_values[6]      = int(list[5]);                 // list[5]
 electrode_values[7]      = int(list[6]);                 // list[6]
 electrode_values[8]      = int(list[7]);                 // list[7]
 electrode_values[9]      = int(list[8]);                 // list[8]
 electrode_values[10]      = int(list[9]);                 // list[9]
 electrode_values[11]     = int(list[10]);                // list[10]
 electrode_values[12]     = int(list[11]);                // list[11]
 print(list[11]);
 //print(electrode_values[12]);
 }