#include "mpr121.h"
#include "i2c.h"

 uint16_t electrode1;
 uint16_t electrode2;  
 uint16_t electrode3;
 uint16_t electrode4;
 uint16_t electrode5;
 uint16_t electrode6;
 uint16_t electrode7;
 uint16_t electrode8;  
 uint16_t electrode9;
 uint16_t electrode10;
 uint16_t electrode11;
 uint16_t electrode12;

 int e1 = 0;
 int e2 = 0;
 int e3 = 0;
 int e4 = 0;
 int e5 = 0;
 int e6 = 0;
 int e7 = 0;
 int e8 = 0;
 int e9 = 0;
 int e10 = 0;
 int e11 = 0;
 int e12 = 0;

 uint16_t electrode1_c [50];
 uint16_t electrode2_c [50];  
 uint16_t electrode3_c [50];
 uint16_t electrode4_c [50];
 uint16_t electrode5_c [50];
 uint16_t electrode6_c [50];
 uint16_t electrode7_c [50];
 uint16_t electrode8_c [50];  
 uint16_t electrode9_c [50];
 uint16_t electrode10_c [50];
 uint16_t electrode11_c [50];
 uint16_t electrode12_c [50];

 uint16_t total_e1;
 uint16_t total_e2;
 uint16_t total_e3;
 uint16_t total_e4;
 uint16_t total_e5;
 uint16_t total_e6;
 uint16_t total_e7;
 uint16_t total_e8;
 uint16_t total_e9;
 uint16_t total_e10;
 uint16_t total_e11;
 uint16_t total_e12;

 uint16_t electrode1_avg;
 uint16_t electrode2_avg;
 uint16_t electrode3_avg;
 uint16_t electrode4_avg;
 uint16_t electrode5_avg;
 uint16_t electrode6_avg;
 uint16_t electrode7_avg;
 uint16_t electrode8_avg;
 uint16_t electrode9_avg;
 uint16_t electrode10_avg;
 uint16_t electrode11_avg;
 uint16_t electrode12_avg;

 uint16_t sample_num = 50;
 uint16_t sensitivity = 10;
 String sensor_datapackage;
 int delay_electrodes = 200;
 
void setup()
{
  //configure serial out
  Serial.begin(115200);
  
  // initalize I2C bus. Wiring lib not used. 
  i2cInit();
  
  // initialize mpr121
  mpr121QuickConfig();
  for(int i = 0; i < sample_num; i++){
  calibrate_electrodes(i);
  }
  average ();
}

void loop()
{
  electrodes();
  sensetouch();
  send_data();
}

//read electrode values from the sensor
 void electrodes(){ 
  electrode1 = getSensorMeasurement(0);
  electrode2 = getSensorMeasurement(1);
  electrode3 = getSensorMeasurement(2);
  electrode4 = getSensorMeasurement(3);
  electrode5 = getSensorMeasurement(4);
  electrode6 = getSensorMeasurement(5);
  electrode7 = getSensorMeasurement(6);
  electrode8 = getSensorMeasurement(7);
  electrode9 = getSensorMeasurement(8);
  electrode10 = getSensorMeasurement(9);
  electrode11 = getSensorMeasurement(10);
  electrode12 = getSensorMeasurement(11);
  delay(delay_electrodes);
  }

  //save the sensor values in arrays for calibration process 
  void calibrate_electrodes(int calibration_value){
  electrodes();
  electrode1_c [calibration_value] = electrode1;
  electrode2_c [calibration_value] = electrode2;  
  electrode3_c [calibration_value] = electrode3;
  electrode4_c [calibration_value] = electrode4;
  electrode5_c [calibration_value] = electrode5;
  electrode6_c [calibration_value] = electrode6;
  electrode7_c [calibration_value] = electrode7;
  electrode8_c [calibration_value] = electrode8;
  electrode9_c [calibration_value] = electrode9;
  electrode10_c [calibration_value] = electrode10;
  electrode11_c [calibration_value] = electrode11;
  electrode12_c [calibration_value] = electrode12;
  }

  //find the average for each electrode
  void average (){
  for (int i = 0; i<sample_num ; i++){
  total_e1 += electrode1_c [i];
  total_e2 += electrode2_c [i];
  total_e3 += electrode3_c [i];
  total_e4 += electrode4_c [i];
  total_e5 += electrode5_c [i];
  total_e6 += electrode6_c [i];
  total_e7 += electrode7_c [i];
  total_e8 += electrode8_c [i];
  total_e9 += electrode9_c [i];
  total_e10 += electrode10_c [i];
  total_e11 += electrode11_c [i];
  total_e12 += electrode12_c [i];
  }  
  electrode1_avg = total_e1 / sample_num;
  electrode2_avg = total_e2 / sample_num;
  electrode3_avg = total_e3 / sample_num;
  electrode4_avg = total_e4 / sample_num;
  electrode5_avg = total_e5 / sample_num;
  electrode6_avg = total_e6 / sample_num;
  electrode7_avg = total_e7 / sample_num;
  electrode8_avg = total_e8 / sample_num;
  electrode9_avg = total_e9 / sample_num;
  electrode10_avg = total_e10 / sample_num;
  electrode11_avg = total_e11 / sample_num;
  electrode12_avg = total_e12 / sample_num;
  }

  //senses if a part of robot head is touched or not
  void sensetouch (){
    if(electrode1 < (electrode1_avg - sensitivity)){
    e1 = 1;
    }
    else {
      e1=0;
    }
    if(electrode2 < (electrode2_avg - sensitivity)){
    e2 = 1;
    }
    else {
      e2=0;
    }
    if(electrode3 < (electrode3_avg - sensitivity)){
    e3 = 1;
    }
    else {
      e3=0;
    }
    if(electrode4 < (electrode4_avg - sensitivity)){
    e4 = 1;
    }
    else {
      e4=0;
    }
    if(electrode5 < (electrode5_avg - sensitivity)){
    e5 = 1;
    }
    else {
      e5=0;
    }
    if(electrode6 < (electrode6_avg - sensitivity)){
    e6 = 1;
    }
    else {
      e6=0;
    }
    if(electrode7 < (electrode7_avg - sensitivity)){
    e7 = 1;
    }
    else {
      e7=0;
    }
    if(electrode8 < (electrode8_avg - sensitivity)){
    e8 = 1;
    }
    else {
      e8=0;
    }
    if(electrode9 < (electrode9_avg - sensitivity)){
    e9 = 1;
    }
    else {
      e9=0;
    }
    if(electrode10 < (electrode10_avg - sensitivity)){
    e10 = 1;
    }
    else {
      e10=0;
    }
    if(electrode11 < (electrode11_avg - sensitivity)){
    e11 = 1;
    }
    else {
    e11=0;
    }
    if(electrode12 < (electrode12_avg - sensitivity)){
    e12 = 1;
    }
    else {
      e12=0;
    }
    }

    void send_data(){
      sensor_datapackage = String(e1) + ":" + String(e2) + ":" + String(e3) + ":" + String(e4) + ":" + String(e5) + ":" + String(e6) + ":" + String(e7) + ":" + String(e8) + ":" + String(e9) + ":" + String(e10) + ":" + String(e11) + ":" + String(e12) + ":";
      Serial.println(sensor_datapackage);
      }

int getSensorMeasurement(byte sensorNumber)
{
  int value = mpr121Read2Bytes(0x04 + (sensorNumber << 1));  
  return value;
}

void mpr121QuickConfig(void)
{
  // reset (in case already running)
  mpr121Write(0x80, 0x63);

  // auto config off  
  mpr121Write(ATO_CFG0, 0x00);
  
  // big sensors, use max charge current
  // FFI = 00 (default)
  // CDC = 111111
  mpr121Write(0x5C, 0x3F);

  // CDT=011 charge time, use the one that fits the size of your sensor best
  // SFI=00 (default)
  // ESI=100 (default)
     mpr121Write(0x5D, 0x24); // CDT=001
  // mpr121Write(0x5D, 0x44); // CDT=010
  //  mpr121Write(0x5D, 0x64); // CDT=011
  //mpr121Write(0x5D, 0x84); // CDT=100
  
  // Electrode Configuration
  mpr121Write(ELE_CFG, 0x0C);	// Enables all 12 Electrodes
  //mpr121Write(ELE_CFG, 0x03);  // Enable first electrode only
}
