//Libraries
#include <FastLED.h>//https://github.com/FastLED/FastLED

#include "bigRing.h"
#include "ring.h"
#include "strip.h"
#include "param.h"

//Constants


// How many NeoPixels are attached to the Arduino?



//Parameters
//Variables
bool gReverseDirection   = false;
colorRGB rgb = {255,0,0};
//Objects



void setup() {
  //Init led strips
  SetupBigRing();
  SetupStrip();
  SetupRing();   

  FastLED.setBrightness( BRIGHTNESS );

  StartRing(rgb);
  StartStrip(rgb);
}
void loop() {
  
  //ledScenario();
    //ShowAllLed(0,255,0);
    CircularColor(0,255,0);
}




void ShowAllLed (int red, int green, int blue)
{
    //ShowLed(big_ring, RING_BIG_NB, red, green, blue);
    ShowLedRing(rgb);
    ShowLedStrip(rgb);
    ShowLedStrip(rgb);
}