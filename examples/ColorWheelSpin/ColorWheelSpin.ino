/**
 * ColorWheelSpin.ino
 * 
 * This example demonstrates how to smoothly transition the RGB backlight
 * of an LCD through a color wheel using the LCD_BacklightRGB library. 
 * 
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

// #include <LiquidCrystal.h>
// #include <LCD_BacklightRGB.h>
// // Set the pins for the LCD display.
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// // Set the RGB pins for the RGB LCD. Use PWM pins denoted by a ~ symbol.
// const int redPin = 6, greenPin = 9, bluePin = 10;
// LCD_BacklightRGB backlight(redPin, greenPin, bluePin);

// unsigned long previousMillis = 0;
// const long interval = 100;
// int index = 0;

// void setup() {
//     // Initiate the LCD.
//     lcd.begin(16, 2);
//     // Initiate the RGB pins.
//     backlight.begin();
//     // Optional: Set the brightness level (0 - 255).
//     backlight.setBrightness(150);
//     lcd.print("hello, world!");
// }

// void loop() {
//     unsigned long currentMillis = millis();
//     if (currentMillis - previousMillis >= interval) {
//         previousMillis = currentMillis;
//         // Smoothly transitions between colors based on the index value.
//         backlight.scaleColor(index, 0, 255);
//         index++;
//         if (index >= 255) {
//             index = 0;
//         }
//         // Update code here.
//     }
// }
