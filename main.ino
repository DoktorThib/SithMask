//Libraries
#include <FastLED.h>//https://github.com/FastLED/FastLED

#include "bigRing.h"
#include "ring.h"
#include "strip.h"
#include "param.h"
#include "mpu6050.h"
#include "led_ctrl.h"

//Constants


// How many NeoPixels are attached to the Arduino?



//Parameters
//Variables
bool gReverseDirection   = false;
colorRGB rgb = {0,255,0};
colorRGB off = {0,0,0};


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
  ShowLedBigRing(off);
}

void loop() {
   //ShowLedFade(0,1,0);
   BigRing_HalfCircle(rgb);
   rgb = {0,255,0};
   BigRing_HalfCircle(rgb);
   rgb = {255,255,0};
   BigRing_HalfCircle(rgb);
   rgb = {0,255,255};
   BigRing_HalfCircle(rgb);
   rgb = {0,0,255};
}
