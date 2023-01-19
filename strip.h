#ifndef STRIP_H_
#define STRIP_H_

#include <Arduino.h>
#include <FastLED.h>
#include "param.h"

#define STRIP_NB        12

void SetupStrip();
void StartStrip(colorRGB rgb);
void ShowLedStrip( colorRGB rgb );

#endif