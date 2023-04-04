#include "bigRing.h"
#include "ring.h"
#include "strip.h"
#include "param.h"
#include "mpu6050.h"
#include "led_ctrl.h"


void ShowAllLed (colorRGB rgbData)
{
    ShowLedRing(rgbData);
    ShowLedStrip(rgbData);
    ShowLedBigRing(rgbData);
}

void ShowLedFade (int R, int G, int B)
{
  int i=0;
  colorRGB rgb;
  for (i=0;i<256;i++){
    rgb = {R*i,G*i,B*i};
    ShowAllLed(rgb);
  }
  delay(200);
  for (i=255;i>-1;i--){
    rgb = {R*i,G*i,B*i};
    ShowAllLed(rgb);
  }
  delay(200);
}