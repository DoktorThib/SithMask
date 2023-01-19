#ifndef BIGRING_H_
#define BIGRING_H_

#include <Arduino.h>
#include <FastLED.h>

#define RING_BIG_NB     24
#define COLOR_ORDER RGB

#define BIG_RING_PIN    2
#define LED_TYPE WS2812B

void CircularColor (int red, int green, int blue);

#endif