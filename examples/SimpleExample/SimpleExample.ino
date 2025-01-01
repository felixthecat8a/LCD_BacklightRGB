/**
 * SimpleExample.ino
 * 
 * This sketch will loop through the different colors and display the color name.
 * This example loops through several default colors available in the library.
 * 
 * Connections:
 * Use an RGB LCD with 18 pins:
 *   Pin 15: Connect to HIGH for backlight power.
 *   Pin 16: Red channel (connect to PWM pin ~6).
 *   Pin 17: Green channel (connect to PWM pin ~9).
 *   Pin 18: Blue channel (connect to PWM pin ~10).
 *   LCD Data Pins:
 *   Register Select: Pin 12
 *   Enable: Pin 11
 *   D4: Pin 5
 *   D5: Pin 4
 *   D6: Pin 3
 *   D7: Pin 2
 *   Read/Write: GND
 *   Vss: GND
 *   Vcc: 5V
 * Contrast Adjustment:
 *   Connect a 10kΩ potentiometer to the contrast (V0) pin.
 *   Middle pin of the potentiometer: Connect to the V0 pin (pin 3) of the LCD.
 *   One outer pin: Connect to GND.
 *   Other outer pin: Connect to 5V.
 * 
 */

#include <LiquidCrystal.h>
#include <LCD_BacklightRGB.h>
// Set the pins for the LCD display.
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Set the RGB pins for the RGB LCD. Use PWM pins denoted by a ~ symbol.
const int redPin = 6, greenPin = 9, bluePin = 10;
LCD_BacklightRGB backlight(redPin, greenPin, bluePin);

// void setup() {
//   // Initiate the LCD.
//   lcd.begin(16, 2);
//   // Initiate the RGB pins.
//   backlight.begin();
//   // Optional: Set the brightness level (0 - 255).
//   // Defaults to 255 if not set.
//   // backlight.setBrightness(150);
//   // Optional: Set the backlight using RGB values.
//   // Defaults to (10, 135, 143) if not set.
//   // backlight.setRGB(46, 139, 87);
//   // Set the color and brightness:
//   backlight.setRGB(46, 139, 87, 150);
//   lcd.home(); lcd.print("Backlight Color:");
//   lcd.setCursor(0,1); lcd.print("Sea Green!");
//   delay(1000);
//   for (int index = 0; index < 16; index++) {
//     lcd.scrollDisplayLeft(); delay(100);
//   }
//   lcd.clear();
// }

// void loop() {
//   // Set the backlight using default colors.
//   backlight.setRed();
//   // Display the name on the second line of the LCD.
//   lcd.setCursor(0,1); lcd.print("Red"); lcd.print("     ");
//   // Change color every second.
//   delay(1000);
  
//   backlight.setYellow();
//   lcd.setCursor(0,1); lcd.print("Yellow"); lcd.print("     ");
//   delay(1000);

//   backlight.setGreen();
//   lcd.setCursor(0,1); lcd.print("Green"); lcd.print("     ");
//   delay(1000);

//   backlight.setCyan();
//   lcd.setCursor(0,1); lcd.print("Cyan"); lcd.print("     ");
//   delay(1000);

//   backlight.setBlue();
//   lcd.setCursor(0,1); lcd.print("Blue"); lcd.print("     ");
//   delay(1000);

//   backlight.setMagenta();
//   lcd.setCursor(0,1); lcd.print("Magenta"); lcd.print("     ");
//   delay(1000);

//   backlight.setPink();
//   lcd.setCursor(0,1); lcd.print("Pink"); lcd.print("     ");
//   delay(1000);
// }