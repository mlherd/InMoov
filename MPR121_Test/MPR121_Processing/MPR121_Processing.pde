import processing.serial.*;

Serial myPort;
int x = 0;


void setup() 
{
  size(1000, 800);
  println(Serial.list());  //list of available serial ports
  String portName = Serial.list()[4]; //replace 0 with whatever port you want to use.
  myPort = new Serial(this, portName, 115200);
  
  fill(0);
  stroke(0);
}


void draw() 
{
}

void serialEvent(Serial myPort) 
{
  String cur = myPort.readStringUntil('\n');
  if(cur != null) 
  {
      float val = float(cur);
        
      background(255);      
      float r = (700-val)*3;
      ellipse(width/2, height/2, r, r);
  }
}
