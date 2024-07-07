// LCD_BacklightRGB.cpp
#include "LCD_BacklightRGB.h"
#include "Colors.h"
#include <Arduino.h>

#define COMMON_ANODE

LCD_BacklightRGB::LCD_BacklightRGB(int redPin, int greenPin, int bluePin) {
  _redPin = redPin;
  _greenPin = greenPin;
  _bluePin = bluePin;
}

void LCD_BacklightRGB::begin() {
  pinMode(_redPin, OUTPUT);
  pinMode(_greenPin, OUTPUT);
  pinMode(_bluePin, OUTPUT);
  // Default Color
  setRGB(Colors::TEAL);
}

int LCD_BacklightRGB::setColor(int color) {
  color = color * _brightness / 255;
  color = constrain(color, minRGB, maxRGB);
  #ifdef COMMON_ANODE
    color = 255 - color;
  #endif
  return color;
}

void LCD_BacklightRGB::setRGB(const int rgb[3]) {
  showRGB(rgb[0], rgb[1], rgb[2]);
}

void LCD_BacklightRGB::setRGB(const int rgb[3], int brightness) {
  _brightness = constrain(brightness, minRGB, maxRGB);
  showRGB(rgb[0], rgb[1], rgb[2]);
}

void LCD_BacklightRGB::setRGB(int red, int green, int blue) {
  showRGB(red, green, blue);
}

void LCD_BacklightRGB::setRGB(int red, int green, int blue, int brightness) {
  _brightness = constrain(brightness, minRGB, maxRGB);
  showRGB(red, green, blue);
}

void LCD_BacklightRGB::showRGB(int red, int green, int blue) {
  _currentColor[0] = red;
  _currentColor[1] = green;
  _currentColor[2] = blue;
  analogWrite(_redPin, setColor(red));
  analogWrite(_greenPin, setColor(green));
  analogWrite(_bluePin, setColor(blue));
}

void LCD_BacklightRGB::setBrightness(int brightness) {
  _brightness = constrain(brightness, minRGB, maxRGB);
  showRGB(_currentColor[0], _currentColor[1], _currentColor[2]);
}

void LCD_BacklightRGB::setRed() {
  setRGB(Colors::RED);
}

void LCD_BacklightRGB::setRed(int brightness) {
  setRGB(Colors::RED, brightness);
}

void LCD_BacklightRGB::setYellow() {
  setRGB(Colors::YELLOW);
}

void LCD_BacklightRGB::setYellow(int brightness) {
  setRGB(Colors::YELLOW, brightness);
}

void LCD_BacklightRGB::setGreen() {
  setRGB(Colors::GREEN);
}

void LCD_BacklightRGB::setGreen(int brightness) {
  setRGB(Colors::GREEN, brightness);
}

void LCD_BacklightRGB::setCyan() {
  setRGB(Colors::CYAN);
}

void LCD_BacklightRGB::setCyan(int brightness) {
  setRGB(Colors::CYAN, brightness);
}

void LCD_BacklightRGB::setBlue() {
  setRGB(Colors::BLUE);
}

void LCD_BacklightRGB::setBlue(int brightness) {
  setRGB(Colors::BLUE, brightness);
}

void LCD_BacklightRGB::setMagenta() {
  setRGB(Colors::MAGENTA);
}

void LCD_BacklightRGB::setMagenta(int brightness) {
  setRGB(Colors::MAGENTA, brightness);
}
