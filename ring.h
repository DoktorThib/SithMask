#ifndef RING_H_
#define RING_H_

#include <Arduino.h>
#include <FastLED.h>
#include "param.h"

#define RING_NB   12

void SetupRing();
void StartRing( colorRGB rgb );
void ShowLedRing( colorRGB rgb );


#endif