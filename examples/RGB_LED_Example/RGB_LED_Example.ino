/**
 * RGB_LED_Example.ino
 *
 * This example demonstrates how to control an RGB LED using the LCD_BacklightRGB library.
 * It cycles through predefined colors and then smoothly transitions through the color wheel.
 *
 * Connections:
 * - Red Pin: PWM pin ~11
 * - Green Pin: PWM pin ~10
 * - Blue Pin: PWM pin ~9
 *
 * felixthecat8a
 */

#include <LiquidCrystal.h>
#include <LCD_BacklightRGB.h>

//Set the RGB pins for the RGB LED. Use PWM pins denoted by a ~ symbol.
const int redPin = 11, greenPin = 10, bluePin = 9;
BacklightRGB led(redPin, greenPin, bluePin);
//Indicate in the constructor if common cathode RGB LED (>= v1.1.9)
//const bool isCommonAnode = false;
//BacklightRGB led(redPin, greenPin, bluePin, isCommonAnode);

// Color wheel utility
//BacklightCW cw;

// Display a predefined color
void showColor(const int color[3]);
// Spin the color wheel
void spinColorWheel();

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

void spinColorWheel() {
  for (int i = 0; i < 359; i++) {
    led.setHSV(i, 1.0, 1.0);
  }
}
