/**
 * @file LCD_BacklightRGB.cpp
 * @brief Implementation of the LCD_BacklightRGB class.
 *
 * @note The LCD_BacklightRGB class provides methods for setting colors and
 * adjusting brightness of the RGB backlight on 18-pin RGB LCD modules.
 */

#include "LCD_BacklightRGB.h"

LCD_BacklightRGB::LCD_BacklightRGB(int r, int g, int b) : rgb(r, g, b) {}

LCD_BacklightRGB::LCD_BacklightRGB(int r, int g, int b, bool isCommonAnode)
    : rgb(r, g, b, isCommonAnode) {}

void LCD_BacklightRGB::begin() {
  rgb.begin();
  rgb.setRGB(0x0A878F); // Set default color to teal
}

void LCD_BacklightRGB::setBrightness(int brightness) {
  rgb.setBrightness(brightness);
}

int LCD_BacklightRGB::getBrightness() {
  return rgb.getBrightness();
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

void LCD_BacklightRGB::setHSV(int hue, float sat, float val) {
  rgb.setHSV(hue, sat, val);
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

void LCD_BacklightRGB::setSpringGreen() {
  rgb.setRGB(BacklightColors::SPRING);
}

void LCD_BacklightRGB::setSpringGreen(int brightness) {
  rgb.setRGB(BacklightColors::SPRING, brightness);
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

void LCD_BacklightRGB::setViolet() {
  rgb.setRGB(BacklightColors::VIOLET);
}

void LCD_BacklightRGB::setViolet(int brightness) {
  rgb.setRGB(BacklightColors::VIOLET, brightness);
}

void LCD_BacklightRGB::setMagenta() {
  rgb.setRGB(BacklightColors::MAGENTA);
}

void LCD_BacklightRGB::setMagenta(int brightness) {
  rgb.setRGB(BacklightColors::MAGENTA, brightness);
}

void LCD_BacklightRGB::setGray() {
  rgb.setRGB(BacklightColors::GRAY);
}

void LCD_BacklightRGB::setGray(int brightness) {
  rgb.setRGB(BacklightColors::GRAY, brightness);
}

void LCD_BacklightRGB::setOlive() {
  rgb.setRGB(BacklightColors::OLIVE);
}

void LCD_BacklightRGB::setOlive(int brightness) {
  rgb.setRGB(BacklightColors::OLIVE, brightness);
}

void LCD_BacklightRGB::setTeal() {
  rgb.setRGB(BacklightColors::TEAL);
}

void LCD_BacklightRGB::setTeal(int brightness) {
  rgb.setRGB(BacklightColors::TEAL, brightness);
}

void LCD_BacklightRGB::setPurple() {
  rgb.setRGB(BacklightColors::PURPLE);
}

void LCD_BacklightRGB::setPurple(int brightness) {
  rgb.setRGB(BacklightColors::PURPLE, brightness);
}

void LCD_BacklightRGB::scaleColor(int value, int fromValue, int toValue) {
  int hue;
  if (fromValue < toValue) {
    value = constrain(value, fromValue, toValue);
    hue = map(value, fromValue, toValue, 0, 360);
  } else if (fromValue > toValue) {
    value = constrain(value, toValue, fromValue);
    hue = map(value, fromValue, toValue, 360, 0);
  } else {
    hue = 0; // Default to Red if range is invalid.
  }
  setHSV(hue);
}
