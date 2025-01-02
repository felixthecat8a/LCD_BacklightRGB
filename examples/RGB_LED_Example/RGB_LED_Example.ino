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
BacklightCW cw;

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
  showColor(BacklightColors::WHITE);
  showColor(BacklightColors::HOTPINK);
  showColor(BacklightColors::RED);
  showColor(BacklightColors::ORANGE);
  showColor(BacklightColors::YELLOW);
  showColor(BacklightColors::LIME);
  showColor(BacklightColors::GREEN);
  showColor(BacklightColors::TEAL);
  showColor(BacklightColors::CYAN);
  showColor(BacklightColors::SKY);
  showColor(BacklightColors::BLUE);
  showColor(BacklightColors::PURPLE);
  showColor(BacklightColors::MAGENTA);
  showColor(BacklightColors::BLACK);
  // Smoothly transition through the color wheel
  spinColorWheel();
}

void showColor(const int color[3]) {
  led.setRGB(color); delay(500);
}

void spinColorWheel() {
  for (int i = 0; i < 255; i++) {
    led.setRGB(cw.mapToColorWheel(i, 0, 255)); delay(15);
  }
}