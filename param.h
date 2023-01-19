#ifndef PARAM_H_
#define PARAM_H_

#include <Arduino.h>
#include "param.h"

#define BIG_RING_PIN    2

#define RING_R          3
#define RING_L          4

#define STIP_R_PIN      5
#define STIP_L_PIN      6


#define LED_TYPE WS2812B

#define BRIGHTNESS 10

#define COLOR_ORDER RGB
#define FASTLED_ALLOW_INTERRUPTS 0
#define FASTLED_INTERRUPT_RETRY_COUNT 1
#define FRAMES_PER_SECOND 60
#define COOLING 55
#define SPARKING 120


struct colorRGB{
    int16_t r;
    int16_t g;
    int16_t b;
};

#endif