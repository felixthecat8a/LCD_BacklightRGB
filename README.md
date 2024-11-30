[![arduino-library-badge](https://www.ardu-badge.com/badge/LCD_BacklightRGB.svg?)](https://www.ardu-badge.com/LCD_BacklightRGB)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/felixthecat8a/library/LCD_BacklightRGB.svg)](https://registry.platformio.org/libraries/felixthecat8a/LCD_BacklightRGB)

# LCD_BacklightRGB

![GitHub Release](https://img.shields.io/github/v/release/felixthecat8a/LCD_BacklightRGB)
[![License: MIT](https://img.shields.io/github/license/felixthecat8a/LCD_BacklightRGB)](https://opensource.org/licenses/MIT)
![GitHub repo size](https://img.shields.io/github/repo-size/felixthecat8a/LCD_BacklightRGB)
![Check Arduino](https://github.com/felixthecat8a/LCD_BacklightRGB/actions/workflows/check-arduino.yml/badge.svg)
![Compile Examples](https://github.com/felixthecat8a/LCD_BacklightRGB/actions/workflows/compile-examples.yml/badge.svg)
![Spell Check](https://github.com/felixthecat8a/LCD_BacklightRGB/actions/workflows/spell-check.yml/badge.svg)

This library allows interfacing with an 18-pin RGB LCD display backlight connected directly to an Arduino board. This library is meant to be used alongside the LiquidCrystal library.

On the RGB LCD display module, set pin 15 to HIGH. Pin 16 is red, pin 17 is green and pin 18 is blue. The code is based on a function that can be used to control the colors on an RGB LED.

## Installation

### Install via ZIP file
1. Download the library *.zip* file from the [latest release](https://github.com/felixthecat8a/LCD_BacklightRGB/releases/latest/).
2. In the Arduino IDE, go to `Sketch` > `Include Library` > `Add .ZIP Library...`.
3. Select the downloaded *.zip* file.


### Install via Arduino IDE Library Manager

1. Open the Arduino IDE.
2. Go to `Tools` > `Manage Libraries...`.
3. In the Library Manager, type "LCD_BacklightRGB" into the search bar.
4. Find the "LCD_BacklightRGB" library in the list and click on it.
5. Click the `Install` button.


## Usage

```cpp
#include <LiquidCrystal.h>
#include <LCD_BacklightRGB.h>
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
    // Set the brightness level. (0 - 255)
    backlight.setBrightness(130);
    // Set the backlight using RGB values.
    backlight.setRGB(0, 255, 0);
}

void loop() {
    // Add your code here.
}
```
## RGB LCD Displays

Here are some of the 18-pin RGB displays that I found:
* The Adafruit RGB LCD displays in  [backlight positive](https://www.adafruit.com/product/398) and [backlight negative](https://www.adafruit.com/product/399).
* Sparkfun also has this one in [backlight positive](https://www.sparkfun.com/products/10862). 
* I found this one on Amazon from Winstar in [backlight negative](https://www.amazon.com/Character-Negative-Backlight-Arduino-projects/dp/B00CRSF37I)

## Known Issues
* Release v1.1.1 has an issue with setting the output values. Update to the latest release to fix the issue.
* Release v1.1.5 and earlier releases have an issue that involves compiling to the arduino-avr-mega platform. Update to the latest release to fix the issue.
