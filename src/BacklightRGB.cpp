/**
 * @file BacklightRGB.cpp
 * @brief Implementation of the BacklightRGB class for controlling RGB LEDs.
 *
 * This file contains the implementation of the `BacklightRGB` class, which provides functionality to control 
 * RGB LEDs connected to Arduino. It supports brightness control and setting colors using RGB components or hexadecimal values.
 */

#include "BacklightRGB.h"

/**
 * @brief Constructor to initialize RGB pins (common anode configuration by default).
 * @param redPin Pin connected to the red LED.
 * @param greenPin Pin connected to the green LED.
 * @param bluePin Pin connected to the blue LED.
 */
BacklightRGB::BacklightRGB(int redPin, int greenPin, int bluePin) {
  _redPin = redPin; _greenPin = greenPin; _bluePin = bluePin;
}

/**
 * @brief Initializes the RGB LED pins as outputs or PWM channels for ESP32.
 */
void BacklightRGB::begin() {
  #ifdef ESP32
    ledcSetup(0, 5000, 8); ///< Channel 0, 5 kHz frequency, 8-bit resolution
    ledcSetup(1, 5000, 8); ///< Channel 1, 5 kHz frequency, 8-bit resolution
    ledcSetup(2, 5000, 8); ///< Channel 2, 5 kHz frequency, 8-bit resolution

    ledcAttachPin(_redPin, 0);  ///< Attach red pin to channel 0
    ledcAttachPin(_greenPin, 1); ///< Attach green pin to channel 1
    ledcAttachPin(_bluePin, 2);  ///< Attach blue pin to channel 2
  #else
    // Default setup for non-ESP32 boards
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
  #endif
}

/**
 * @brief Sets the brightness of the LED.
 * @param brightness Brightness value (0 to 255).
 */
void BacklightRGB::setBrightness(int brightness) {
  _brightness = constrain(brightness, 0, 255);
  showRGB(_currentColor[0], _currentColor[1], _currentColor[2]);
}

/**
 * @brief Sets the RGB color using an array.
 * @param rgb Array containing red, green, and blue values.
 */
void BacklightRGB::setRGB(const int rgb[3]) {
  showRGB(rgb[0], rgb[1], rgb[2]);
}

/**
 * @brief Sets the RGB color and brightness using an array.
 * @param rgb Array containing red, green, and blue values.
 * @param brightness Brightness value (0 to 255).
 */
void BacklightRGB::setRGB(const int rgb[3], int brightness) {
  _brightness = constrain(brightness, 0, 255);
  showRGB(rgb[0], rgb[1], rgb[2]);
}

/**
 * @brief Sets the RGB color using red, green, and blue values.
 * @param red Red value (0 to 255).
 * @param green Green value (0 to 255).
 * @param blue Blue value (0 to 255).
 */
void BacklightRGB::setRGB(int red, int green, int blue) {
  showRGB(red, green, blue);
}

/**
 * @brief Sets the RGB color and brightness using red, green, and blue values.
 * @param red Red value (0 to 255).
 * @param green Green value (0 to 255).
 * @param blue Blue value (0 to 255).
 * @param brightness Brightness value (0 to 255).
 */
void BacklightRGB::setRGB(int red, int green, int blue, int brightness) {
  _brightness = constrain(brightness, 0, 255);
  showRGB(red, green, blue);
}

/**
 * @brief Sets the RGB color using a hexadecimal value.
 * @param hexColor 24-bit hexadecimal value representing the color (e.g., 0xRRGGBB).
 */
void BacklightRGB::setRGB(uint32_t hexColor) {
  int red = (hexColor >> 16) & 0xFF;
  int green = (hexColor >> 8) & 0xFF;
  int blue = hexColor & 0xFF;
  showRGB(red, green, blue);
}

/**
 * @brief Sets the RGB color and brightness using a hexadecimal value.
 * @param hexColor 24-bit hexadecimal value representing the color (e.g., 0xRRGGBB).
 * @param brightness Brightness value (0 to 255).
 */
void BacklightRGB::setRGB(uint32_t hexColor, int brightness) {
  _brightness = constrain(brightness, 0, 255);
  int red = (hexColor >> 16) & 0xFF;
  int green = (hexColor >> 8) & 0xFF;
  int blue = hexColor & 0xFF;
  showRGB(red, green, blue);
}

/**
 * @brief Adjusts the intensity of a color component based on brightness and configuration.
 * @param color Original color component value (0 to 255).
 * @return Adjusted color value considering brightness and common anode/cathode configuration.
 */
int BacklightRGB::setColor(int color) {
  color = constrain(color, 0, 255);
  color = color * _brightness / 255;
  if (COMMON_ANODE) {
    color = 255 - color;
  }
  return color;
}

/**
 * @brief Updates the RGB LED with the specified red, green, and blue values.
 * @param red Red value (0 to 255).
 * @param green Green value (0 to 255).
 * @param blue Blue value (0 to 255).
 */
void BacklightRGB::showRGB(int red, int green, int blue) {
    _currentColor[0] = red;
    _currentColor[1] = green;
    _currentColor[2] = blue;

  #ifdef ESP32
    // Use ESP32 PWM for RGB values
    ledcWrite(0, setColor(red));   ///< Write red value to channel 0
    ledcWrite(1, setColor(green)); ///< Write green value to channel 1
    ledcWrite(2, setColor(blue));  ///< Write blue value to channel 2
  #else
    // Use analogWrite for non-ESP32 boards
    analogWrite(_redPin, setColor(red));
    analogWrite(_greenPin, setColor(green));
    analogWrite(_bluePin, setColor(blue));
  #endif
}
