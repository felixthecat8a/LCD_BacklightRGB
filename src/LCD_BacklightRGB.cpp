/**
 * @file LCD_BacklightRGB.cpp
 * @brief Implementation of the BacklightRGB class for controlling an RGB backlight.
 *
 * This class provides methods to control an RGB backlight, including setting colors,
 * brightness levels, and predefined color presets.
 */
#include "LCD_BacklightRGB.h"

/**
 * @brief Constructor for the BacklightRGB class.
 * @param r Pin for the red LED.
 * @param g Pin for the green LED.
 * @param b Pin for the blue LED.
 */
LCD_BacklightRGB::LCD_BacklightRGB(int r, int g, int b):rgb(r, g, b) {}

/**
 * @brief Constructor for the BacklightRGB class.
 * @param r Pin for the red LED.
 * @param g Pin for the green LED.
 * @param b Pin for the blue LED.
 * @param isCommonAnode Boolean variable indicating common anode RGB LED.
 */
LCD_BacklightRGB::LCD_BacklightRGB(int r, int g, int b, bool isCommonAnode)
  :rgb(r, g, b, isCommonAnode) {}

/**
 * @brief Initializes the RGB backlight.
 * @note Sets the initial color to a default teal (hex: 0x0A878F).
 */
void LCD_BacklightRGB::begin() {
  rgb.begin();
  rgb.setRGB(0x0A878F);
}

/**
 * @brief Sets the brightness of the backlight.
 * @param brightness Brightness level (0 to 255).
 */
void LCD_BacklightRGB::setBrightness(int brightness) {
  rgb.setBrightness(brightness);
}

/**
 * @brief Sets the RGB color using individual color components.
 * @param red Red intensity (0 to 255).
 * @param green Green intensity (0 to 255).
 * @param blue Blue intensity (0 to 255).
 */
void LCD_BacklightRGB::setRGB(int red, int green, int blue) {
  rgb.setRGB(red, green, blue);
}

/**
 * @brief Sets the RGB color and brightness using individual color components.
 * @param red Red intensity (0 to 255).
 * @param green Green intensity (0 to 255).
 * @param blue Blue intensity (0 to 255).
 * @param brightness Brightness level (0 to 255).
 */
void LCD_BacklightRGB::setRGB(int red, int green, int blue, int brightness) {
  rgb.setRGB(red, green, blue, brightness);
}

/**
 * @brief Sets the RGB color using a hexadecimal color value.
 * @param hexColor Hexadecimal representation of the color (e.g., 0xFF0000 for red).
 */
void LCD_BacklightRGB::setRGB(uint32_t hexColor) {
  rgb.setRGB(hexColor);
}

/**
 * @brief Sets the RGB color and brightness using a hexadecimal color value.
 * @param hexColor Hexadecimal representation of the color (e.g., 0xFF0000 for red).
 * @param brightness Brightness level (0 to 255).
 */
void LCD_BacklightRGB::setRGB(uint32_t hexColor, int brightness) {
  rgb.setRGB(hexColor, brightness);
}

/**
 * @brief Method for setting the values to (0, 0, 0).
 */
void LCD_BacklightRGB::off() {
  rgb.setRGB(BacklightColors::BLACK);
}

/**
 * @brief Predefined color methods for setting specific colors with optional brightness.
 * @note Colors include pink, red, orange, yellow, lime green, green, teal, cyan, sky blue,
 * blue, purple, magenta, and white.
 * @note Brightness can also be set for each color.
 */
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

/**
 * @brief Maps a value to a color on the color wheel.
 * @param value The input value to map.
 * @param fromValue The minimum range of the input value.
 * @param toValue The maximum range of the input value.
 */
void LCD_BacklightRGB::scaleColor(int value, int fromValue, int toValue) {
  rgb.setRGB(cw.mapToColorWheel(value, fromValue, toValue));
}

/**
 * @brief Sets the RGB LED color using HSV (Hue, Saturation, Value).
 * @param hue The hue value (0-360 degrees).
 * @param sat The saturation level (0.0-1.0).
 * @param val The brightness value (0.0-1.0).
 */
void LCD_BacklightRGB::setHSV(int hue, float sat, float val) {
    float r, g, b;
    hue = constrain(hue, 0, 359);
    int i = hue / 60;
    float f = (hue / 60.0) - i;
    float p = val * (1 - sat);
    float q = val * (1 - sat * f);
    float t = val * (1 - sat * (1 - f));

    switch (i % 6) {
        case 0: r = val, g = t, b = p; break;
        case 1: r = q, g = val, b = p; break;
        case 2: r = p, g = val, b = t; break;
        case 3: r = p, g = q, b = val; break;
        case 4: r = t, g = p, b = val; break;
        case 5: r = val, g = p, b = q; break;
        default: r = g = b = 0; break;
    }

    rgb.setRGB((int)(r * 255), (int)(g * 255), (int)(b * 255));
}
