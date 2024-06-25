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
}

int LCD_BacklightRGB::setColor(int color) {
  color = constrain(color, minRGB, maxRGB);
  #ifdef COMMON_ANODE
    color = 255 - color;
  #endif
  return color;
}

void LCD_BacklightRGB::setRGB(const int rgb[3]) {
  analogWrite(_redPin, setColor(rgb[0]));
  analogWrite(_greenPin, setColor(rgb[1]));
  analogWrite(_bluePin, setColor(rgb[2]));
}

void LCD_BacklightRGB::setRGB(int red, int green, int blue) {
  analogWrite(_redPin, setColor(red));
  analogWrite(_greenPin, setColor(green));
  analogWrite(_bluePin, setColor(blue));
}

void LCD_BacklightRGB::setRed() {
  setRGB(Colors::RED);
}

void LCD_BacklightRGB::setYellow() {
  setRGB(Colors::YELLOW);
}

void LCD_BacklightRGB::setGreen() {
  setRGB(Colors::GREEN);
}

void LCD_BacklightRGB::setCyan() {
  setRGB(Colors::CYAN);
}

void LCD_BacklightRGB::setBlue() {
  setRGB(Colors::BLUE);
}