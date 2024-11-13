// LCD_BacklightRGB.cpp
#include "LCD_BacklightRGB.h"

LCD_BacklightRGB::LCD_BacklightRGB(int r, int g, int b):rgb(r, g, b) {}

void LCD_BacklightRGB::begin() {
  rgb.begin();
  rgb.setRGB(70, 215, 190);
}

void LCD_BacklightRGB::setBrightness(int brightness) {
  rgb.setBrightness(brightness);
}

void LCD_BacklightRGB::setRGB(int red, int green, int blue) {
  rgb.setRGB(red, green, blue);
}

void LCD_BacklightRGB::setRGB(int red, int green, int blue, int brightness) {
  rgb.setRGB(red, green, blue, brightness);
}

void LCD_BacklightRGB::setWhite() {
  rgb.setRGB(Colors::WHITE);
}

void LCD_BacklightRGB::setWhite(int brightness) {
  rgb.setRGB(Colors::WHITE, brightness);
}

void LCD_BacklightRGB::setRed() {
  rgb.setRGB(Colors::RED);
}

void LCD_BacklightRGB::setRed(int brightness) {
  rgb.setRGB(Colors::RED, brightness);
}

void LCD_BacklightRGB::setOrange() {
  rgb.setRGB(Colors::ORANGE);
}

void LCD_BacklightRGB::setOrange(int brightness) {
  rgb.setRGB(Colors::ORANGE, brightness);
}

void LCD_BacklightRGB::setYellow() {
  rgb.setRGB(Colors::YELLOW);
}

void LCD_BacklightRGB::setYellow(int brightness) {
  rgb.setRGB(Colors::YELLOW, brightness);
}

void LCD_BacklightRGB::setLimeGreen() {
  rgb.setRGB(Colors::LIME);
}

void LCD_BacklightRGB::setLimeGreen(int brightness) {
  rgb.setRGB(Colors::LIME, brightness);
}

void LCD_BacklightRGB::setGreen() {
  rgb.setRGB(Colors::GREEN);
}

void LCD_BacklightRGB::setGreen(int brightness) {
  rgb.setRGB(Colors::GREEN, brightness);
}

void LCD_BacklightRGB::setTeal() {
  rgb.setRGB(Colors::TEAL);
}

void LCD_BacklightRGB::setTeal(int brightness) {
  rgb.setRGB(Colors::TEAL, brightness);
}

void LCD_BacklightRGB::setCyan() {
  rgb.setRGB(Colors::CYAN);
}

void LCD_BacklightRGB::setCyan(int brightness) {
  rgb.setRGB(Colors::CYAN, brightness);
}

void LCD_BacklightRGB::setSkyBlue() {
  rgb.setRGB(Colors::SKY);
}

void LCD_BacklightRGB::setSkyBlue(int brightness) {
  rgb.setRGB(Colors::SKY, brightness);
}

void LCD_BacklightRGB::setBlue() {
  rgb.setRGB(Colors::BLUE);
}

void LCD_BacklightRGB::setBlue(int brightness) {
  rgb.setRGB(Colors::BLUE, brightness);
}

void LCD_BacklightRGB::setPurple() {
  rgb.setRGB(Colors::PURPLE);
}

void LCD_BacklightRGB::setPurple(int brightness) {
  rgb.setRGB(Colors::PURPLE, brightness);
}

void LCD_BacklightRGB::setMagenta() {
  rgb.setRGB(Colors::MAGENTA);
}

void LCD_BacklightRGB::setMagenta(int brightness) {
  rgb.setRGB(Colors::MAGENTA, brightness);
}

void LCD_BacklightRGB::setPink() {
  rgb.setRGB(Colors::PINK);
}

void LCD_BacklightRGB::setPink(int brightness) {
  rgb.setRGB(Colors::PINK, brightness);
}

void LCD_BacklightRGB::off() {
  rgb.setRGB(Colors::BLACK);
}
