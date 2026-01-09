#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 1     // Один RGB светодиод
#define DATA_PIN 48    // WS2812 data pin

CRGB leds[NUM_LEDS];

void fadeToColor(CRGB targetColor, uint16_t steps = 50, uint16_t stepDelay = 15) {
    CRGB startColor = leds[0];

    for (uint16_t i = 0; i <= steps; i++) {
        leds[0].r = startColor.r + ((int)targetColor.r - startColor.r) * i / steps;
        leds[0].g = startColor.g + ((int)targetColor.g - startColor.g) * i / steps;
        leds[0].b = startColor.b + ((int)targetColor.b - startColor.b) * i / steps;

        FastLED.show();
        delay(stepDelay);
    }
}

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

    // гарантируем старт с выключенного состояния
    leds[0] = CRGB::Black;
    FastLED.show();

    // плавно загорелся зелёным
    fadeToColor(CRGB::Green, 40, 15);

    // небольшая пауза на пике
    delay(150);

    // плавно погас
    fadeToColor(CRGB::Black, 40, 15);
}

void loop() {
    // пусто — индикатор только при старте
}
