#include "mpu6050.h"
#include "led_ctrl.h"
 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
MPU_deg MPU_deg_val;

/*Min max to convert data in degree*/ 
int minVal=265;
int maxVal=402;

MPU_deg MPU_values;
MPU_deg MPU_values_prev;

/**/
int xAng = 0 , yAng = 0, zAng = 0; 
/*Help to switch to two states*/
int16_t flag = 0;
int16_t mode = 0;

/*Init MPU6050*/
void SetupMPU(){
    Wire.begin();
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
    Serial.begin(9600);

    /*Init MPU values data to 0 (avoid strange data)*/
    MPU_values ={180.0,110.0,0.0};

    /*Get the first data*/
    MPU_values = MPU_get_data ();
}

MPU_deg MPU_get_data(){
/*Connection request*/
Wire.beginTransmission(MPU_ADDR);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU_ADDR,14,true);

/*Read angle date from sensor*/
AcX=Wire.read()<<8|Wire.read();
AcY=Wire.read()<<8|Wire.read();
AcZ=Wire.read()<<8|Wire.read();

/*Maping to radian value*/
xAng = map(AcX,minVal,maxVal,-90,90);
yAng = map(AcY,minVal,maxVal,-90,90);
zAng = map(AcZ,minVal,maxVal,-90,90);
/*Convert data to degree*/
MPU_deg_val.degX = RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
MPU_deg_val.degY = RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
MPU_deg_val.degZ = RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
return MPU_deg_val;
}

void MPU_switch_yes(){
    //get the value of MPU orientation
  MPU_deg MPU_values = MPU_get_data ();
  colorRGB rgb = {0,0,0};

  /*Set a new mode when you are looking down and update flag that block repetition mode*/
  if ((DOWN_Y-10 < MPU_values.degY && MPU_values.degY < DOWN_Y+10) && 0 == flag){
    if( 0 == mode){
      mode ++;
      rgb = {0,0,255};
    }
    else if (1 == mode){
      mode ++;
      rgb = {255,255,0};
    }
    else{
      mode = 0;
      rgb = {255,0,255};
    }
    ShowAllLed(rgb);
    flag = 1;
  }
  /*reset Flag when you are looking forward !*/
  if ((MID_Y-10 < MPU_values.degY && MPU_values.degY < MID_Y+10) && 1 == flag){
    flag = 0;
  }
  delay(50); 
}