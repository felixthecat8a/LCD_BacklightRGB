// LCD_BacklightRGB.cpp
#include "LCD_BacklightRGB.h"
#include "Colors.h"

#define COMMON_ANODE

LCD_BacklightRGB::LCD_BacklightRGB(int redPin, int greenPin, int bluePin) {
  _redPin = redPin;
  _greenPin = greenPin;
  _bluePin = bluePin;
  _brightness = 255;
}

void LCD_BacklightRGB::begin() {
  pinMode(_redPin, OUTPUT);
  pinMode(_greenPin, OUTPUT);
  pinMode(_bluePin, OUTPUT);
  // Default Color
  setRGB(10, 128, 128);
}

int LCD_BacklightRGB::setColor(int color) {
  color = constrain(color, 0, 255);
  color = color * _brightness / 255;
  #ifdef COMMON_ANODE
    color = 255 - color;
  #endif
  return color;
}

void LCD_BacklightRGB::setRGB(const int rgb[3]) {
  showRGB(rgb[0], rgb[1], rgb[2]);
}

void LCD_BacklightRGB::setRGB(const int rgb[3], int brightness) {
  _brightness = constrain(brightness, 0, 255);
  showRGB(rgb[0], rgb[1], rgb[2]);
}

void LCD_BacklightRGB::setRGB(int red, int green, int blue) {
  showRGB(red, green, blue);
}

void LCD_BacklightRGB::setRGB(int red, int green, int blue, int brightness) {
  _brightness = constrain(brightness, 0, 255);
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
  _brightness = constrain(brightness, 0, 255);
  showRGB(_currentColor[0], _currentColor[1], _currentColor[2]);
}

void LCD_BacklightRGB::setWhite() {
  setRGB(Colors::WHITE);
}

void LCD_BacklightRGB::setWhite(int brightness) {
  setRGB(Colors::WHITE, brightness);
}

void LCD_BacklightRGB::setRed() {
  setRGB(Colors::RED);
}

void LCD_BacklightRGB::setRed(int brightness) {
  setRGB(Colors::RED, brightness);
}

void LCD_BacklightRGB::setOrange() {
  setRGB(Colors::ORANGE);
}

void LCD_BacklightRGB::setOrange(int brightness) {
  setRGB(Colors::ORANGE, brightness);
}

void LCD_BacklightRGB::setYellow() {
  setRGB(Colors::YELLOW);
}

void LCD_BacklightRGB::setYellow(int brightness) {
  setRGB(Colors::YELLOW, brightness);
}

//set lime green default

void LCD_BacklightRGB::setGreen() {
  setRGB(Colors::GREEN);
}

void LCD_BacklightRGB::setGreen(int brightness) {
  setRGB(Colors::GREEN, brightness);
}

//set teal default

void LCD_BacklightRGB::setCyan() {
  setRGB(Colors::CYAN);
}

void LCD_BacklightRGB::setCyan(int brightness) {
  setRGB(Colors::CYAN, brightness);
}

//set sky blue default

void LCD_BacklightRGB::setBlue() {
  setRGB(Colors::BLUE);
}

void LCD_BacklightRGB::setBlue(int brightness) {
  setRGB(Colors::BLUE, brightness);
}

//set purple default

void LCD_BacklightRGB::setMagenta() {
  setRGB(Colors::MAGENTA);
}

void LCD_BacklightRGB::setMagenta(int brightness) {
  setRGB(Colors::MAGENTA, brightness);
}

//set pink default

void LCD_BacklightRGB::off() {
  setRGB(Colors::BLACK);
}