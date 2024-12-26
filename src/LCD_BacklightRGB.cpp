// LCD_BacklightRGB.cpp
#include "LCD_BacklightRGB.h"

LCD_BacklightRGB::LCD_BacklightRGB(int r, int g, int b):rgb(r, g, b) {}

void LCD_BacklightRGB::begin() {
  rgb.begin();
  rgb.setRGB(0x0A878F);
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

void LCD_BacklightRGB::setRGB(uint32_t hexColor) {
  rgb.setRGB(hexColor);
}

void LCD_BacklightRGB::setRGB(uint32_t hexColor, int brightness) {
  rgb.setRGB(hexColor, brightness);
}

void LCD_BacklightRGB::off() {
  rgb.setRGB(BacklightColors::BLACK);
}

void LCD_BacklightRGB::setWhite() {
  rgb.setRGB(BacklightColors::WHITE);
}

void LCD_BacklightRGB::setWhite(int brightness) {
  rgb.setRGB(BacklightColors::WHITE, brightness);
}

void LCD_BacklightRGB::setPink() {
  rgb.setRGB(BacklightColors::HOTPINK);
}

void LCD_BacklightRGB::setPink(int brightness) {
  rgb.setRGB(BacklightColors::HOTPINK, brightness);
}

void LCD_BacklightRGB::setRed() {
  rgb.setRGB(BacklightColors::RED);
}

void LCD_BacklightRGB::setRed(int brightness) {
  rgb.setRGB(BacklightColors::RED, brightness);
}

void LCD_BacklightRGB::setOrange() {
  rgb.setRGB(BacklightColors::ORANGE);
}

void LCD_BacklightRGB::setOrange(int brightness) {
  rgb.setRGB(BacklightColors::ORANGE, brightness);
}

void LCD_BacklightRGB::setYellow() {
  rgb.setRGB(BacklightColors::YELLOW);
}

void LCD_BacklightRGB::setYellow(int brightness) {
  rgb.setRGB(BacklightColors::YELLOW, brightness);
}

void LCD_BacklightRGB::setLimeGreen() {
  rgb.setRGB(BacklightColors::LIME);
}

void LCD_BacklightRGB::setLimeGreen(int brightness) {
  rgb.setRGB(BacklightColors::LIME, brightness);
}

void LCD_BacklightRGB::setGreen() {
  rgb.setRGB(BacklightColors::GREEN);
}

void LCD_BacklightRGB::setGreen(int brightness) {
  rgb.setRGB(BacklightColors::GREEN, brightness);
}

void LCD_BacklightRGB::setTeal() {
  rgb.setRGB(BacklightColors::TEAL);
}

void LCD_BacklightRGB::setTeal(int brightness) {
  rgb.setRGB(BacklightColors::TEAL, brightness);
}

void LCD_BacklightRGB::setCyan() {
  rgb.setRGB(BacklightColors::CYAN);
}

void LCD_BacklightRGB::setCyan(int brightness) {
  rgb.setRGB(BacklightColors::CYAN, brightness);
}

void LCD_BacklightRGB::setSkyBlue() {
  rgb.setRGB(BacklightColors::SKY);
}

void LCD_BacklightRGB::setSkyBlue(int brightness) {
  rgb.setRGB(BacklightColors::SKY, brightness);
}

void LCD_BacklightRGB::setBlue() {
  rgb.setRGB(BacklightColors::BLUE);
}

void LCD_BacklightRGB::setBlue(int brightness) {
  rgb.setRGB(BacklightColors::BLUE, brightness);
}

void LCD_BacklightRGB::setPurple() {
  rgb.setRGB(BacklightColors::PURPLE);
}

void LCD_BacklightRGB::setPurple(int brightness) {
  rgb.setRGB(BacklightColors::PURPLE, brightness);
}

void LCD_BacklightRGB::setMagenta() {
  rgb.setRGB(BacklightColors::MAGENTA);
}

void LCD_BacklightRGB::setMagenta(int brightness) {
  rgb.setRGB(BacklightColors::MAGENTA, brightness);
}
