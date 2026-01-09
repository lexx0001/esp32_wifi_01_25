#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 48
#define BRIGHTNESS 30

CRGB leds[NUM_LEDS];

const char* WIFI_SSID = "BACbKA_Guest";
const char* WIFI_PASS = "10111213";

void setLedHSV(uint8_t hue, uint8_t sat = 255) {
    leds[0] = CHSV(hue, sat, 255);   // ❗ val = 255
    FastLED.show();
}

void setup() {
    Serial.begin(115200);
    delay(500);

    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);

    FastLED.clear(true);

    Serial.println("WiFi test started");

    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    uint8_t attempts = 0;

    // 🟡 мигаем жёлтым при подключении
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        setLedHSV(32);   // жёлтый
        delay(300);
        FastLED.clear(true);
        delay(300);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi connected!");
        Serial.println(WiFi.localIP());
        setLedHSV(160);  // 🔵 синий
    } else {
        Serial.println("\nWiFi FAILED");
        setLedHSV(0);    // 🔴 красный
    }
}

void loop() {}
