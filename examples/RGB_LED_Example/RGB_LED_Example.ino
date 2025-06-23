/**
 * @file RGB_LED_Example.ino
 *
 * This example demonstrates how to control an RGB LED using BacklightRGB.h
 * and BacklightColors.h found in the LCD_BacklightRGB library.
 *
 * It  first cycles through predefined colors and then smoothly transitions
 * through the color wheel.
 *
 * Wire connections for this example:
 * - Red Pin: PWM pin ~11
 * - Green Pin: PWM pin ~10
 * - Blue Pin: PWM pin ~9
 *
 * @author https://github.com/felixthecat8a
 */

#include <LCD_BacklightRGB.h>

//Set the RGB pins for the RGB LED. Use PWM pins denoted by a ~ symbol.
const int redPin = 11, greenPin = 10, bluePin = 9;
BacklightRGB led(redPin, greenPin, bluePin);
//Indicate in the constructor if common cathode RGB LED (>= v1.1.9)
//const bool isCommonAnode = false;
//BacklightRGB led(redPin, greenPin, bluePin, isCommonAnode);

// Spin the color wheel
void spinColorWheel() {
    for (int hue = 0; hue < 359; hue++) {
      led.setHSV(hue, 1.0, 1.0);
      delay(50);
    }
  }

void setup() {
  // Initialize the RGB LED
  led.begin();
  // Set brightness (0-255)
  led.setBrightness(50);
}

void loop() {
  // Cycle through predefined colors
  led.setRGB(BacklightColors::WHITE); delay(500);
  led.setRGB(BacklightColors::HOTPINK); delay(500);
  led.setRGB(BacklightColors::RED); delay(500);
  led.setRGB(BacklightColors::ORANGE); delay(500);
  led.setRGB(BacklightColors::YELLOW); delay(500);
  led.setRGB(BacklightColors::LIME); delay(500);
  led.setRGB(BacklightColors::GREEN); delay(500);
  led.setRGB(BacklightColors::TEAL); delay(500);
  led.setRGB(BacklightColors::CYAN); delay(500);
  led.setRGB(BacklightColors::SKY); delay(500);
  led.setRGB(BacklightColors::BLUE); delay(500);
  led.setRGB(BacklightColors::PURPLE); delay(500);
  led.setRGB(BacklightColors::MAGENTA); delay(500);
  led.setRGB(BacklightColors::BLACK); delay(500);
  // Smoothly transition through the color wheel
  spinColorWheel();
}
