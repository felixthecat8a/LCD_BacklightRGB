/**
 * @file BacklightRGB.cpp
 * @brief Implementation of the BacklightRGB class for controlling RGB LEDs.
 *
 * This file contains the implementation of the `BacklightRGB` class, which provides functionality to control
 * RGB LEDs connected to Arduino. It supports brightness control and setting colors using RGB components or hexadecimal values.
 */

#include "BacklightRGB.h"


BacklightRGB::BacklightRGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) {
  _redPin = redPin; _greenPin = greenPin; _bluePin = bluePin;
  _COMMON_ANODE = true;
  _brightness = 255;
  _currentColor[0] = _currentColor[1] = _currentColor[2] = 0;
}

BacklightRGB::BacklightRGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, bool COMMON_ANODE) {
  _redPin = redPin; _greenPin = greenPin; _bluePin = bluePin;
  _COMMON_ANODE = COMMON_ANODE;
  _brightness = 255;
  _currentColor[0] = _currentColor[1] = _currentColor[2] = 0;
}

void BacklightRGB::begin() {
  #ifdef ESP32
    // Updated from 2.x
    // ledcSetup(0, 5000, 8); ///< Channel 0, 5 kHz frequency, 8-bit resolution
    // ledcSetup(1, 5000, 8); ///< Channel 1, 5 kHz frequency, 8-bit resolution
    // ledcSetup(2, 5000, 8); ///< Channel 2, 5 kHz frequency, 8-bit resolution

    // ledcAttachPin(_redPin, 0);    ///< Attach red pin to channel 0
    // ledcAttachPin(_greenPin, 1);  ///< Attach green pin to channel 1
    // ledcAttachPin(_bluePin, 2);   ///< Attach blue pin to channel 2

    // to 3.x
    ledcAttach(_redPin, 5000, 8);    ///< red pin, 5 kHz frequency, 8-bit resolution
    ledcAttach(_greenPin, 5000, 8);  ///< green pin, 5 kHz frequency, 8-bit resolution
    ledcAttach(_bluePin, 5000, 8);   ///< blue pin, 5 kHz frequency, 8-bit resolution
  #else
    // Default setup for non-ESP32 boards
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
  #endif
}

void BacklightRGB::setBrightness(uint8_t brightness) {
  _brightness = constrain(brightness, 0, 255);
  showRGB(_currentColor[0], _currentColor[1], _currentColor[2]);
}

int BacklightRGB::getBrightness() const {
    return _brightness;
}

void BacklightRGB::setRGB(const uint8_t rgb[3]) {
  showRGB(rgb[0], rgb[1], rgb[2]);
}

void BacklightRGB::setRGB(const uint8_t rgb[3], uint8_t brightness) {
  _currentColor[0] = rgb[0];
  _currentColor[1] = rgb[1];
  _currentColor[2] = rgb[2];
  setBrightness(brightness);
}

void BacklightRGB::setRGB(uint8_t red, uint8_t green, uint8_t blue) {
  showRGB(red, green, blue);
}

void BacklightRGB::setRGB(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness) {
  _currentColor[0] = red;
  _currentColor[1] = green;
  _currentColor[2] = blue;
  setBrightness(brightness);
}

void BacklightRGB::setHex(uint32_t hexColor) {
  uint8_t red = (hexColor >> 16) & 0xFF;
  uint8_t green = (hexColor >> 8) & 0xFF;
  uint8_t blue = hexColor & 0xFF;
  showRGB(red, green, blue);
}

void BacklightRGB::setHex(uint32_t hexColor, uint8_t brightness) {
  uint8_t red = (hexColor >> 16) & 0xFF;
  uint8_t green = (hexColor >> 8) & 0xFF;
  uint8_t blue = hexColor & 0xFF;
  _currentColor[0] = red;
  _currentColor[1] = green;
  _currentColor[2] = blue;
  setBrightness(brightness);
}

uint8_t BacklightRGB::setColor(uint8_t color) {
  color = constrain(color, 0, 255);
  color = color * _brightness / 255;
  if (_COMMON_ANODE) {
    color = 255 - color;
  }
  return color;
}

void BacklightRGB::showRGB(uint8_t red, uint8_t green, uint8_t blue) {
    _currentColor[0] = red;
    _currentColor[1] = green;
    _currentColor[2] = blue;

    #ifdef ESP32
        // Updated from 2.x
        // ledcWrite(0, setColor(red));   ///< Write red value to channel 0
        // ledcWrite(1, setColor(green)); ///< Write green value to channel 1
        // ledcWrite(2, setColor(blue));  ///< Write blue value to channel 2

        // to 3.x
        ledcWrite(_redPin, setColor(red));
        ledcWrite(_greenPin, setColor(green));
        ledcWrite(_bluePin, setColor(blue));
    #else
        // Use analogWrite for non-ESP32 boards
        analogWrite(_redPin, setColor(red));
        analogWrite(_greenPin, setColor(green));
        analogWrite(_bluePin, setColor(blue));
    #endif
}

const uint8_t* BacklightRGB::getRGB() const {
  return _currentColor;
}

uint32_t BacklightRGB::getColorHex() const {
    return (_currentColor[0] << 16) | (_currentColor[1] << 8) | _currentColor[2];
}

void BacklightRGB::setHSV(int hue, float sat, float val) {
  float red, green, blue;
  hue = constrain(hue, 0, 359);
  sat = constrain(sat, 0.0f, 1.0f);
  val = constrain(val, 0.0f, 1.0f);
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

void BacklightRGB::setCMYK(float cyan, float magenta, float yellow, float key) {
  cyan = constrain(cyan, 0.0f, 1.0f);
  magenta = constrain(magenta, 0.0f, 1.0f);
  yellow = constrain(yellow, 0.0f, 1.0f);
  float black = constrain(key, 0.0f, 1.0f);
  int red   = roundf((1 - cyan) * (1 - black) * 255);
  int green = roundf((1 - magenta) * (1 - black) * 255);
  int blue  = roundf((1 - yellow) * (1 - black) * 255);
  setRGB(red, green, blue);
}
