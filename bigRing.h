#ifndef BIGRING_H_
#define BIGRING_H_

#include <Arduino.h>
#include <FastLED.h>
#include "param.h"

#define RING_BIG_NB     24
#define COLOR_ORDER RGB


void SetupBigRing ();
void ShowLedBigRing( colorRGB rgb );

void BigRing_CircularColor (int red, int green, int blue);

void BigRing_HalfCircle( colorRGB rgb);

#endif