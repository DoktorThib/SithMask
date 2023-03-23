#ifndef PARAM_H_
#define PARAM_H_

#include <Arduino.h>
#include <Wire.h>
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

/*MPU param*/
#define MPU_ADDR 0x68

#define DOWN_Y 95
#define MID_Y  116
#define UP_Y   144

#define ROT_RIGHT   123
#define ROT_CASUAL  180
#define ROT_LEFT    249

struct colorRGB{
    int16_t r;
    int16_t g;
    int16_t b;
};

struct MPU_deg{
    double degX;
    double degY;
    double degZ;
};

#endif