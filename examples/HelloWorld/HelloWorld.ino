/**
 * HelloWorld.ino
 * For an RGB LCD with 18 pins, set pin 15 to HIGH.
 * Pin 16 is red, pin 17 is green and pin 18 is blue.
*/

#include <LiquidCrystal.h>

#include "LCD_BacklightRGB.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Choose three PWM pins (denoted by ~)
const int redPin = 6, greenPin = 9, bluePin = 10;
LCD_BacklightRGB backlight(redPin, greenPin, bluePin);

void setup() {
  // Initiate the LCD
  lcd.begin(16, 2);
  // initiate the backlight RGB pins
  backlight.begin();
  // Set the brightness level (0 - 255) 
  // The default value is 255.
  backlight.setBrightness(130);
  // Set the backlight using RGB values
  // If the color is not set, the default color is (0, 128, 128)
  backlight.setRGB(0, 255, 255);
  lcd.print("hello, world!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
}
