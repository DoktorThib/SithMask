//Libraries
#include <FastLED.h>//https://github.com/FastLED/FastLED

#include "bigRing.h"

//Constants



#define RING_R          3
#define RING_L          4

#define STIP_R_PIN      5
#define STIP_L_PIN      6

// How many NeoPixels are attached to the Arduino?
#define STRIP_NB        12
#define RING_SMALL_NB   12

#define NUM_STRIPS 1
#define NUM_LEDS 60
#define BRIGHTNESS 10

#define COLOR_ORDER RGB
#define FASTLED_ALLOW_INTERRUPTS 0
#define FASTLED_INTERRUPT_RETRY_COUNT 1
#define FRAMES_PER_SECOND 60
#define COOLING 55
#define SPARKING 120

//Parameters
//Variables
bool gReverseDirection   = false;
//Objects
CRGB ring_L[RING_SMALL_NB];
CRGB ring_R[RING_SMALL_NB];
CRGB strip_L[STRIP_NB];
CRGB strip_R[STRIP_NB];



void setup() {
  //Init led strips
  
    FastLED.addLeds<LED_TYPE, RING_L, COLOR_ORDER>(ring_L, RING_SMALL_NB);
    FastLED.addLeds<LED_TYPE, RING_R, COLOR_ORDER>(ring_R, RING_SMALL_NB);
    FastLED.addLeds<LED_TYPE, STIP_L_PIN, COLOR_ORDER>(strip_L, STRIP_NB);
    FastLED.addLeds<LED_TYPE, STIP_R_PIN, COLOR_ORDER>(strip_R, STRIP_NB);

  FastLED.setBrightness(  BRIGHTNESS );

  //ShowAllLed(255,215,0);
  Start(0,255,0);
}
void loop() {
  
  //ledScenario();
    //ShowAllLed(0,255,0);
    CircularColor(0,255,0);
    //CircularColor(0,215,0);
    //CircularColor(0,215,255);
    //CircularColor(0,0,255);
}

void ShowLed(CRGB strip[RING_BIG_NB], int nbLed, int red, int green, int blue)
{
    int i=0;
    for(i=0;i < nbLed; i++)
    {
        strip[i].setRGB(red, green, blue);
    }
    FastLED.show();
    delay(50);
}


void ShowAllLed (int red, int green, int blue)
{
    //ShowLed(big_ring, RING_BIG_NB, red, green, blue);
    ShowLed(ring_L, RING_SMALL_NB, red, green, blue);
    ShowLed(ring_R, RING_SMALL_NB, red, green, blue);
    ShowLed(strip_L, STRIP_NB, red, green, blue);
    ShowLed(strip_R, STRIP_NB, red, green, blue);
}

void Start(int red, int green, int blue)
{
  int i=0;
    for(i=0;i < RING_SMALL_NB; i++)
    {
      ring_L[i].setRGB(red, green, blue);
      ring_R[i].setRGB(red, green, blue);
      FastLED.show();
      delay(50); 
    }

    for(i=0;i < STRIP_NB; i++)
    {
      strip_L[i].setRGB(red, green, blue);
      strip_R[i].setRGB(red, green, blue);
      FastLED.show();
      delay(50); 
    }
}
