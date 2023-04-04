#include "ring.h"

CRGB ring_L[RING_NB];
CRGB ring_R[RING_NB];

void SetupRing()
{
    FastLED.addLeds<LED_TYPE, RING_L, COLOR_ORDER>(ring_L, RING_NB);
    FastLED.addLeds<LED_TYPE, RING_R, COLOR_ORDER>(ring_R, RING_NB);
}

void StartRing( colorRGB rgb )
{
  int i=0;
    for(i=0;i < RING_NB; i++)
    {
      ring_L[i].setRGB(rgb.r, rgb.g, rgb.b);
      ring_R[i].setRGB(rgb.r, rgb.g, rgb.b);
      FastLED.show();
      delay(50); 
    }
}

void ShowLedRing( colorRGB rgb )
{
    int i=0;
    /*Display all leds*/
    for(i=0 ;i < RING_NB ; i++)
    {
        ring_L[i].setRGB(rgb.r, rgb.g, rgb.b);
        ring_R[i].setRGB(rgb.r, rgb.g, rgb.b);
    }
    FastLED.show();
    //delay(1);
}