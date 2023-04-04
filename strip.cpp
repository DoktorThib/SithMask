#include "strip.h"

CRGB strip_L[STRIP_NB];
CRGB strip_R[STRIP_NB];

void SetupStrip(){
    FastLED.addLeds<LED_TYPE, STIP_L_PIN, COLOR_ORDER>(strip_L, STRIP_NB);
    FastLED.addLeds<LED_TYPE, STIP_R_PIN, COLOR_ORDER>(strip_R, STRIP_NB);
}

void StartStrip(colorRGB rgb){
    int i=0;

    for(i=0;i < STRIP_NB; i++)
    {
        strip_L[i].setRGB(rgb.r, rgb.g, rgb.b);
        strip_R[i].setRGB(rgb.r, rgb.g, rgb.b);
        FastLED.show();
        delay(50); 
    }
}

void ShowLedStrip( colorRGB rgb )
{
    int i=0;
    for(i=0 ;i < STRIP_NB ; i++)
    {
        strip_L[i].setRGB(rgb.r, rgb.g, rgb.b);
        strip_R[i].setRGB(rgb.r, rgb.g, rgb.b);
    }
    FastLED.show();
    //delay(50);
}