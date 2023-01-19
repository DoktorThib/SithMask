#include "bigRing.h"

CRGB big_ring[RING_BIG_NB];

void Setup (){
  FastLED.addLeds<LED_TYPE, BIG_RING_PIN, COLOR_ORDER>(big_ring, RING_BIG_NB);
}
void CircularColor (int red, int green, int blue)
{
  int i =0;

  for (i=0; i < RING_BIG_NB; i++)
  {
    big_ring[i].setRGB(red, green, blue);
    big_ring[i+1].setRGB(red, green, blue);
    big_ring[i+2].setRGB(red, green, blue);

    big_ring[i-1].setRGB(0, 0, 0);
    big_ring[i-2].setRGB(0, 0, 0);
    big_ring[i-3].setRGB(0, 0, 0); 

    if(0 == i)
    {
      big_ring[RING_BIG_NB].setRGB(0, 0, 0);
      big_ring[RING_BIG_NB-1].setRGB(0, 0, 0);
      big_ring[RING_BIG_NB-2].setRGB(0, 0, 0);
    }
    else if (1 == i)
    {
      big_ring[RING_BIG_NB].setRGB(0, 0, 0);
      big_ring[RING_BIG_NB-1].setRGB(0, 0, 0);
    }
    else if (2 == i)
    {
      big_ring[RING_BIG_NB].setRGB(0, 0, 0);
    }

    else if( RING_BIG_NB == i)
    {      
      big_ring[0].setRGB(red, green, blue);
      big_ring[1].setRGB(red, green, blue);
      big_ring[2].setRGB(red, green, blue);
    }
    else if ((RING_BIG_NB-1) == i)
    {
      big_ring[i-1].setRGB(0, 0, 0);
      big_ring[i-2].setRGB(0, 0, 0);
      big_ring[i-3].setRGB(0, 0, 0);
      
      big_ring[RING_BIG_NB-1].setRGB(red, green, blue);
      big_ring[RING_BIG_NB].setRGB(red, green, blue);
      big_ring[0].setRGB(red, green, blue);
    }
    
    FastLED.show();
    delay(50);    
  }
}
