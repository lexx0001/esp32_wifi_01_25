#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 1     // Один светодиод на плате
#define DATA_PIN 48    // Пин данных WS2812

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

// Функция плавного перехода от текущего цвета к targetColor
void fadeToColor(CRGB targetColor, uint16_t steps = 50, uint16_t stepDelay = 20) {
    CRGB startColor = leds[0];
    for (uint16_t i = 1; i <= steps; i++) {
        leds[0].r = startColor.r + ((int)targetColor.r - startColor.r) * i / steps;
        leds[0].g = startColor.g + ((int)targetColor.g - startColor.g) * i / steps;
        leds[0].b = startColor.b + ((int)targetColor.b - startColor.b) * i / steps;
        FastLED.show();
        delay(stepDelay);
    }
}

void loop() {
    // Плавно красный
    fadeToColor(CRGB::Red);
    delay(500);

    // Плавно зелёный
    fadeToColor(CRGB::Green);
    delay(500);

    // Плавно синий
    fadeToColor(CRGB::Blue);
    delay(500);

    // Плавно белый
    fadeToColor(CRGB::White);
    delay(500);

    // Плавно выключаем
    fadeToColor(CRGB::Black);
    delay(500);
}
