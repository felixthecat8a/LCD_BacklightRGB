/**
 * SimpleExample.ino
 * For an RGB LCD with 18 pins, set pin 15 to HIGH.
 * Pin 16 is red, pin 17 is green and pin 18 is blue.
 * This sketch will loop through the different colors 
 * and display the color name.
*/

#include <LiquidCrystal.h>

#include "LCD_BacklightRGB.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// set the RGB pins for the RGB LCD
const int redPin = 6;
const int greenPin = 9;
const int bluePin = 10;
LCD_BacklightRGB backlight(redPin, greenPin, bluePin);

void setup() {
  // Initiate the LCD.
  lcd.begin(16, 2);
  // Initiate the RGB pins.
  backlight.begin();
  // Set the backlight using RGB values.
  backlight.setRGB(0, 128, 128);
  lcd.print("Backlight Color:");
  lcd.setCursor(0,1); 
  lcd.print("Teal! ");
  delay(500);
}

void loop() {
  // set the backlight using RGB values
  lcd.setCursor(0,1); 
  backlight.setRGB(255,0,0);
  lcd.print("Red!  ");
  delay(1000);
  // change color every second
  lcd.setCursor(0,1); 
  backlight.setRGB(0,255,0);
  lcd.print("Green!");
  delay(1000);

  lcd.setCursor(0,1); 
  backlight.setRGB(0,0,255);
  lcd.print("Blue! ");
  delay(1000);
}