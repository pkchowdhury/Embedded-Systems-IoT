#include <FastLED.h>

#define LED_PIN     5   // define the led pin
#define NUM_LEDS    20 //define the no. of leds

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}

void loop() {

  for (int i = 0; i <= 19; i++) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(40);
  }
  for (int i = 19; i >= 0; i--) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(40);
  }
}
