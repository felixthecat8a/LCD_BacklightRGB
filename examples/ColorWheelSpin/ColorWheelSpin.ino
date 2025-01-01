/**
 * ColorWheelSpin.ino
 * 
 * This sketch will loop through the colors of a color wheel.
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