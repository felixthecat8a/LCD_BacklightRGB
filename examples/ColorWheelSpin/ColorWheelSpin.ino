/**
 * ColorWheelSpin.ino
 * For an RGB LCD with 18 pins, set pin 15 to HIGH.
 * Pin 16 is red, pin 17 is green and pin 18 is blue.
 * On the Arduino board, choose 3 PWM pins (denoted by ~)
 * This sketch will change the color of the backlight as the LCD displays
*/

#include <LiquidCrystal.h>
#include <LCD_BacklightRGB.h>
// Set the pins for the LCD display.
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Set the RGB pins for the RGB LCD. Use PWM pins denoted by a ~ symbol.
const int redPin = 6, greenPin = 9, bluePin = 10;
LCD_BacklightRGB backlight(redPin, greenPin, bluePin);

unsigned long previousMillis = 0;
const long interval = 1000;
int index = 0;

void setup() {
    // Initiate the LCD.
    lcd.begin(16, 2);
    // Initiate the RGB pins.
    backlight.begin();
    // Optional: Set the brightness level (0 - 255).
    // Defaults to 255 if not set.
    backlight.setBrightness(150);
    lcd.print("hello, world!");
}

void loop() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        backlight.scaleColor(index, 0, 255);
        index++;
        if (index >= 255) {
            index = 0;
        }
    }
}
