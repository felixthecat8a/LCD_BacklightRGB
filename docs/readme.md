
This library allows interfacing with an 18-pin RGB LCD display backlight connected directly to an Arduino board. This library is meant to be used alongside the LiquidCrystal library.

On the RGB LCD display module, set pin 15 to HIGH. Pin 16 is red, pin 17 is green and pin 18 is blue.

# Usage

* Include the *LiquidCrystal* and *LCD_BacklightRGB* .h files.
* Create the LCD and Backlight objects
* Adjust the pin values to your project board setup as needed. Try to use PWM enabled pins for the RGB backlight pins.
```cpp
#include <LiquidCrystal.h>
#include <LCD_BacklightRGB.h>
// Set up the LiquidCrystal library
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Set up the LCD_BacklightRGB library
const int redPin = 6, greenPin = 9, bluePin = 10;
LCD_BacklightRGB backlight(redPin, greenPin, bluePin);
```

* initiate the LiquidCrystal and LCD_BacklightRGB libraries.
* Optional: Set the brightness level (0 - 255). (Defaults to 255 if not set.)
* Optional: Set the backlight using RGB values. (Defaults to (30, 128, 128) if not set.)

```cpp
void setup() {
    lcd.begin(16, 2);
    backlight.begin();

    backlight.setBrightness(130); // optional
    backlight.setRGB(0, 255, 0); // optional
}
```

* Use the method `setRGB()` to update the backlight color in the loop code or use the default color methods `setWhite()`, `setRed()`, `setYellow()`, `setGreen()`, `setCyan()`, `setBlue()` & `setMagenta()`.
* Turn the backlight off with the method `off()`.

```cpp
void loop() {
  backlight.setRed();
  lcd.setCursor(0,0); lcd.print("Red"); lcd.print("       ");
  delay(1000); // Change color every second.
  
  backlight.setGreen();
  lcd.setCursor(0,0); lcd.print("Green"); lcd.print("       ");
  delay(1000);

  backlight.setBlue();
  lcd.setCursor(0,0); lcd.print("Blue"); lcd.print("       ");
  delay(1000);

  backlight.off();
  delay(500);
}
```

## Known Issues
* Release v1.1.1 has an issue with setting the ouput values. Update to the latest release to fix the issue.