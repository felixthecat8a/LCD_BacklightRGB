/**
 * SimpleExample.ino
 * For an RGB LCD with 18 pins, set pin 15 to HIGH.
 * Pin 16 is red, pin 17 is green and pin 18 is blue.
 * On the Arduino board, choose 3 PWM pins (denoted by ~)
 * This sketch will loop through the different colors and display the color name.
 * This example loops through all of the default colors available in the library.
*/

#include <LiquidCrystal.h>
#include <LCD_BacklightRGB.h>
// Set the pins for the LCD display.
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Set the RGB pins for the RGB LCD. Use PWM pins denoted by a ~ symbol.
const int redPin = 6, greenPin = 9, bluePin = 10;
LCD_BacklightRGB backlight(redPin, greenPin, bluePin);

void setup() {
  // Initiate the LCD.
  lcd.begin(16, 2);
  // Initiate the RGB pins.
  backlight.begin();
  // Optional: Set the brightness level (0 - 255). (Defaults to 255 if not set.)
  backlight.setBrightness(150);
  // Optional: Set the backlight using RGB values. (Defaults to (30, 128, 128) if not set.)
  backlight.setRGB(46, 139, 87);
  // or set the color and brightness at the same time:
  //backlight.setRGB(46, 139, 87, 150);
  lcd.home(); lcd.print("Backlight Color:");
  lcd.setCursor(0,1); lcd.print("Sea Green!");
  delay(1000);
  for (int index = 0; index < 16; index++) {
    lcd.scrollDisplayLeft(); delay(100);
  }
  lcd.clear();
}

void loop() {
  // Set the backlight using default colors.
  backlight.setRed();
  // Display the name on the second line of the LCD.
  lcd.setCursor(0,1); lcd.print("Red!      ");
  // Change color every second.
  delay(1000);
  
  backlight.setYellow();
  lcd.setCursor(0,1); lcd.print("Yellow!   ");
  delay(1000);

  backlight.setGreen();
  lcd.setCursor(0,1); lcd.print("Green!    ");
  delay(1000);

  backlight.setCyan();
  lcd.setCursor(0,1); lcd.print("Cyan!     ");
  delay(1000);

  backlight.setBlue();
  lcd.setCursor(0,1); lcd.print("Blue!     ");
  delay(1000);

  backlight.setMagenta();
  lcd.setCursor(0,1); lcd.print("Magenta!  ");
  delay(1000);
}