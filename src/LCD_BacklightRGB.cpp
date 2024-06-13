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

void LCD_BacklightRGB::setRGB(int red, int green, int blue) {
  red = constrain(red, minRGB, maxRGB);
  green = constrain(green, minRGB, maxRGB);
  blue = constrain(blue, minRGB, maxRGB);

  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif

  analogWrite(_redPin, red);
  analogWrite(_greenPin, green);
  analogWrite(_bluePin, blue);
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