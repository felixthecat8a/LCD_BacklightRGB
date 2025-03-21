/**
 * @file BacklightRGB.cpp
 * @brief Implementation of the BacklightRGB class for controlling RGB LEDs.
 *
 * This file contains the implementation of the `BacklightRGB` class, which provides functionality to control
 * RGB LEDs connected to Arduino. It supports brightness control and setting colors using RGB components or hexadecimal values.
 */

#include "BacklightRGB.h"

/**
 * @brief Constructor to initialize RGB pins.
 * @param redPin Pin connected to the red LED.
 * @param greenPin Pin connected to the green LED.
 * @param bluePin Pin connected to the blue LED.
 * @note common anode configuration by default
 */
BacklightRGB::BacklightRGB(int redPin, int greenPin, int bluePin) {
  _redPin = redPin; _greenPin = greenPin; _bluePin = bluePin;
  _COMMON_ANODE = true;
}

/**
 * @brief Constructor to initialize RGB pins.
 * @param redPin Pin connected to the red LED.
 * @param greenPin Pin connected to the green LED.
 * @param bluePin Pin connected to the blue LED.
 * @param COMMON_ANODE Boolean variable indicating common anode RGB LED.
 */
BacklightRGB::BacklightRGB(int redPin, int greenPin, int bluePin, bool COMMON_ANODE) {
  _redPin = redPin; _greenPin = greenPin; _bluePin = bluePin;
  _COMMON_ANODE = COMMON_ANODE;
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
 * @brief Gets the current brightness level.
 * @return Brightness value (0 to 255).
 */
int BacklightRGB::getBrightness() {
    return _brightness;
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
  _currentColor[0] = rgb[0];
  _currentColor[1] = rgb[1];
  _currentColor[2] = rgb[2];
  setBrightness(brightness);
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
  _currentColor[0] = red;
  _currentColor[1] = green;
  _currentColor[2] = blue;
  setBrightness(brightness);
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
  int red = (hexColor >> 16) & 0xFF;
  int green = (hexColor >> 8) & 0xFF;
  int blue = hexColor & 0xFF;
  _currentColor[0] = red;
  _currentColor[1] = green;
  _currentColor[2] = blue;
  setBrightness(brightness);
}

/**
 * @brief Adjusts the intensity of a color component based on brightness and configuration.
 * @param color Original color component value (0 to 255).
 * @return Adjusted color value considering brightness and common anode/cathode configuration.
 */
int BacklightRGB::setColor(int color) {
  color = constrain(color, 0, 255);
  color = color * _brightness / 255;
  if (_COMMON_ANODE) {
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

/**
 * @brief Gets the current RGB color.
 * @return Pointer to an array containing red, green, and blue values.
 */
const int* BacklightRGB::getRGB() {
    return _currentColor;
}

/**
 * @brief Gets the current color as a 24-bit hexadecimal value.
 * @return 24-bit integer representing the color (0xRRGGBB).
 */
uint32_t BacklightRGB::getColorHex() {
    return (_currentColor[0] << 16) | (_currentColor[1] << 8) | _currentColor[2];
}

/**
 * @brief Sets the RGB LED color using HSV (Hue, Saturation, Value).
 * @param hue The hue value (0-360 degrees).
 * @param sat The saturation level (0.0-1.0).
 * @param val The brightness value (0.0-1.0).
 */
void BacklightRGB::setHSV(int hue, float sat, float val) {
    float red, green, blue;
    hue = constrain(hue, 0, 359);
    sat = constrain(sat, 0.0, 1.0);
    val = constrain(val, 0.0, 1.0);
    int i = hue / 60;
    float f = (hue / 60.0) - i;
    float p = val * (1 - sat);
    float q = val * (1 - sat * f);
    float t = val * (1 - sat * (1 - f));

    switch (i % 6) {
        case 0: red = val, green = t, blue = p; break;
        case 1: red = q, green = val, blue = p; break;
        case 2: red = p, green = val, blue = t; break;
        case 3: red = p, green = q, blue = val; break;
        case 4: red = t, green = p, blue = val; break;
        case 5: red = val, green = p, blue = q; break;
        default: red = green = blue = 0; break;
    }

    setRGB((int)(red * 255), (int)(green * 255), (int)(blue * 255));
}
