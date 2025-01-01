/**
 * RGB_LED.ino
 * 
 * This sketch will change the color of an RGB LED using the sub libraries available.
*/

#include <Arduino.h>
#include <LCD_BacklightRGB.h>

// Set the RGB pins for the RGB LED. Use PWM pins denoted by a ~ symbol.
const int redPin = 11, greenPin = 10, bluePin = 9;
BacklightRGB led(redPin, greenPin, bluePin);

BacklightCW cw;

void showColor(const int color[3]);
void spinColorWheel();

void setup() {
    led.begin();
    led.setBrightness(50);
}

void loop() {
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


/**
 * RGB_LED.ino
 * 
 * This example demonstrates how to control an RGB LED using the LCD_BacklightRGB library.
 * It cycles through predefined colors and then smoothly transitions through the color wheel.
 * 
 * Features:
 * - Predefined colors using BacklightColors.
 * - Smooth color transitions using the color wheel (BacklightCW).
 * - Adjustable brightness for the RGB LED.
 * 
 * Connections:
 * - Red Pin: PWM pin ~11
 * - Green Pin: PWM pin ~10
 * - Blue Pin: PWM pin ~9
 */

 #include <Arduino.h>
 #include <LCD_BacklightRGB.h>
 
 // Set the RGB pins for the RGB LED. Use PWM pins denoted by a ~ symbol.
 const int redPin = 11, greenPin = 10, bluePin = 9;
 BacklightRGB led(redPin, greenPin, bluePin);
 
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
     // Set the LED to the specified RGB color
     led.setRGB(color);
     delay(500);
 }
 
 void spinColorWheel() {
     // Smoothly transition through the color wheel
     for (int i = 0; i < 255; i++) {
         led.setRGB(cw.mapToColorWheel(i, 0, 255));
         delay(15);
     }
 }
 