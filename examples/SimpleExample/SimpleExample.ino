/**
 * SimpleExample.ino
 * For an RGB LCD with 18 pins, set pin 15 to HIGH.
 * Pin 16 is red, pin 17 is green and pin 18 is blue.
 * On the Arduino board, choose 3 PWM pins (denoted by ~)
 * This sketch will loop through the different colors 
 * and display the color name.
 * This example loops through all of the default colors
 * available in the library.
*/

#include <LiquidCrystal.h>

#include "LCD_BacklightRGB.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Set the RGB pins for the RGB LCD. 
// Use PWM pin denoted by ~ symbol.
const int redPin = 6, greenPin = 9, bluePin = 10;
LCD_BacklightRGB backlight(redPin, greenPin, bluePin);

void setup() {
  // Initiate the LCD.
  lcd.begin(16, 2);
  // Initiate the RGB pins.
  backlight.begin();
  // Set the brightness level (0 - 255). (optional)
  // If not set, the default value is 255
  backlight.setBrightness(150);
  // Set the backlight using RGB values. (optional)
  // If not set, the default value is (10, 128, 128)
  backlight.setRGB(10, 150, 150);
  // or set the color and brightness at the same time:
  //backlight.setRGB(10, 150, 150, 150);
  lcd.home();
  lcd.print("Backlight Color:");
}

void loop() {
  lcd.setCursor(0,1); 
  // set the backlight using default colors
  backlight.setRed();
  lcd.print("Red!     ");
  delay(1000);
  // change color every second
  lcd.setCursor(0,1); 
  backlight.setYellow();
  lcd.print("Yellow!  ");
  delay(1000);

  lcd.setCursor(0,1); 
  backlight.setGreen();
  lcd.print("Green!   ");
  delay(1000);

  lcd.setCursor(0,1); 
  backlight.setCyan();
  lcd.print("Cyan!    ");
  delay(1000);

  lcd.setCursor(0,1); 
  backlight.setBlue();
  lcd.print("Blue!    ");
  delay(1000);
}