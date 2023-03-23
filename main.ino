//Libraries
#include <FastLED.h>//https://github.com/FastLED/FastLED

#include "bigRing.h"
#include "ring.h"
#include "strip.h"
#include "param.h"
#include "mpu6050.h"

//Constants


// How many NeoPixels are attached to the Arduino?



//Parameters
//Variables
bool gReverseDirection   = false;
colorRGB rgb = {0,255,0};
MPU_deg MPU_values;
MPU_deg MPU_values_prev;

int16_t mode = 0;
int16_t flag = 0;
//Objects



void setup() {

  Serial.begin(9600);
  /*Init MPU accelero/Gyro*/
  SetupMPU();

  /*Init strip leds*/
  SetupBigRing();
  SetupStrip();
  SetupRing();   

  FastLED.setBrightness( BRIGHTNESS );

  StartRing(rgb);
  StartStrip(rgb);

  /*Start mode*/
  ShowAllLed(rgb);

/*Init MPU values data to 0 (avoid strange data)*/
  MPU_values ={180.0,110.0,0.0};

  /*Get the first data*/
  MPU_values = MPU_get_data ();
}

void loop() {
  MPU_values = MPU_get_data ();
    Serial.print("MPU_values.degY ");
  Serial.println(MPU_values.degY);
  Serial.print("Flag ");
  Serial.println(flag);

  /*Set a new mode when you are looking down and update flag that block repetition mode*/
  if ((DOWN_Y-10 < MPU_values.degY && MPU_values.degY < DOWN_Y+10) && 0 == flag){
    Serial.println("mode ");
    Serial.println(mode);
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
    Serial.println("Gonna show led");
    ShowAllLed(rgb);
    flag = 1;
  }
  /*reset Flag when you are looking forward !*/
  if ((MID_Y-10 < MPU_values.degY && MPU_values.degY < MID_Y+10) && 1 == flag){
    flag = 0;
  }

  delay(50);
}

void ShowAllLed (colorRGB rgbData)
{
    //ShowLed(big_ring, RING_BIG_NB, red, green, blue);
    ShowLedRing(rgbData);
    ShowLedStrip(rgbData);
    ShowLedBigRing(rgbData);
}