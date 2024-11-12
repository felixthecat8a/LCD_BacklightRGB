// RGB.cpp
#include "RGB.h"

RGB::RGB(int redPin, int greenPin, int bluePin) {
  _redPin = redPin; _greenPin = greenPin; _bluePin = bluePin;
}

void RGB::begin() {
  pinMode(_redPin, OUTPUT);
  pinMode(_greenPin, OUTPUT);
  pinMode(_bluePin, OUTPUT);
}

void RGB::setBrightness(int brightness) {
  _brightness = constrain(brightness, 0, 255);
  showRGB(_currentColor[0], _currentColor[1], _currentColor[2]);
}

void RGB::setRGB(const int rgb[3]) {
  showRGB(rgb[0], rgb[1], rgb[2]);
}

void RGB::setRGB(const int rgb[3], int brightness) {
  _brightness = constrain(brightness, 0, 255);
  showRGB(rgb[0], rgb[1], rgb[2]);
}

void RGB::setRGB(int red, int green, int blue) {
  showRGB(red, green, blue);
}

void RGB::setRGB(int red, int green, int blue, int brightness) {
  _brightness = constrain(brightness, 0, 255);
  showRGB(red, green, blue);
}

int RGB::setColor(int color) {
  color = constrain(color, 0, 255);
  color = color * _brightness / 255;
  if (COMMON_ANODE) {
    color = 255 - color;
  }
  return color;
}

void RGB::showRGB(int red, int green, int blue) {
  _currentColor[0] = red; _currentColor[1] = green; _currentColor[2] = blue;
  analogWrite(_redPin, setColor(red));
  analogWrite(_greenPin, setColor(green));
  analogWrite(_bluePin, setColor(blue));
}
