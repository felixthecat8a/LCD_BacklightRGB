/**
 * HelloWorld.ino
 * For an RGB LCD with 18 pins, set pin 15 to HIGH.
 * Pin 16 is red, pin 17 is green and pin 18 is blue.
*/

#include <LiquidCrystal.h>

#include "LCD_BacklightRGB.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int redPin = 6, greenPin = 9, bluePin = 10;
LCD_BacklightRGB backlight(redPin, greenPin, bluePin);

void setup() {
    lcd.begin(16, 2);
    // initiate the backlight pins
    backlight.begin();
    // set the backlight using RGB values
    backlight.setRGB(0, 255, 255);
    lcd.print("hello, world!");
}

void loop() {
    lcd.setCursor(0, 1);
    lcd.print(millis()/1000);
}
