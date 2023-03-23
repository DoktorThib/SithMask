#include "mpu6050.h"
 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
MPU_deg MPU_deg_val;

/*Min max to convert data in degree*/ 
int minVal=265;
int maxVal=402;

/**/
int xAng = 0 , yAng = 0, zAng = 0; 


/*Init MPU6050*/
void SetupMPU(){
    Wire.begin();
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
    Serial.begin(9600);
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