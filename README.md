# LCD_BacklightRGB

This library allows interfacing with an RGB LCD display backlight. It enables the user to control the RGB backlight using Arduino.

For an RGB LCD with 18 pins, set pin 15 to HIGH. Pin 16 is red, pin 17 is green and pin 18 is blue. This sketch will loop through the different colors and display the color name.

## Installation

1. Download the library as a ZIP file.
2. In the Arduino IDE, go to `Sketch` > `Include Library` > `Add .ZIP Library...`.
3. Select the downloaded ZIP file.

## Usage

```cpp
#include <LiquidCrystal.h>
#include "LCD_BacklightRGB.h"
// Set up the LiquidCrystal library
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Set up the LCD_BacklightRGB library
const int redPin = 6, greenPin = 9, bluePin = 10;
LCD_BacklightRGB backlight(redPin, greenPin, bluePin);

void setup() {
    // Initiate the LCD.
    lcd.begin(16, 2);
    // Initiate the RGB pins.
    backlight.begin();
    // Set the backlight using RGB values.
    backlight.setRGB(0, 255, 0);
    lcd.print("Green!");
    delay(500);
    lcd.clear();
}

void loop() {
    // Add your loop code here.
}
