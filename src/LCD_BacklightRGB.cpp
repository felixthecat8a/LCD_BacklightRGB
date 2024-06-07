// LCD_BacklightRGB.cpp
#include "LCD_BacklightRGB.h"
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

void LCD_BacklightRGB::display(int red, int green, int blue) {
  analogWrite(_redPin, red);
  analogWrite(_greenPin, green);
  analogWrite(_bluePin, blue);
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

  LCD_BacklightRGB::display(red, green, blue);
}

void LCD_BacklightRGB::setRed() {
  LCD_BacklightRGB::setRGB(255, 0, 0);
}

void LCD_BacklightRGB::setYellow() {
  LCD_BacklightRGB::setRGB(255, 255, 0);
}

void LCD_BacklightRGB::setGreen() {
  LCD_BacklightRGB::setRGB(0, 255, 0);
}

void LCD_BacklightRGB::setCyan() {
  LCD_BacklightRGB::setRGB(0, 255, 255);
}

void LCD_BacklightRGB::setBlue() {
  LCD_BacklightRGB::setRGB(0, 0, 255);
}