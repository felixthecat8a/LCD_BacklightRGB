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
 * @brief Gets the current brightness level.
 * @return Brightness value (0 to 255).
 */
int LCD_BacklightRGB::getBrightness() {
    return rgb.getBrightness();
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
 * @brief Sets the RGB LED color using HSV (Hue, Saturation, Value).
 * @param hue The hue value (0-360 degrees).
 * @param sat The saturation level (0.0-1.0).
 * @param val The brightness value (0.0-1.0).
 */
void LCD_BacklightRGB::setHSV(int hue, float sat, float val) {
    rgb.setHSV(hue, sat, val);
}

/**
 * @brief Method for setting the values to (0, 0, 0).
 */
void LCD_BacklightRGB::off() {
  rgb.setRGB(BacklightColors::BLACK);
}

// /**
//  * @brief Maps a value to a color on the color wheel.
//  * @param value The input value to map.
//  * @param fromValue The minimum range of the input value.
//  * @param toValue The maximum range of the input value.
//  */
// void LCD_BacklightRGB::scaleColor(int value, int fromValue, int toValue) {
//     int hue;
//     if (fromValue < toValue) {
//         value = constrain(value, fromValue, toValue);
//         hue = map(value, fromValue, toValue, 0, 360);
//     } else if (fromValue > toValue) {
//         value = constrain(value, toValue, fromValue);
//         hue = map(value, fromValue, toValue, 360, 0);
//     } else {
//         hue = 0; // Default to Red if range is invalid.
//     }
//     setHSV(hue);
// }
