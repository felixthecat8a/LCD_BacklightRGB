/**
 * @file BacklightRGB.h
 * @brief Header file for the RGB class.
 *
 * The `BacklightRGB` class provides an interface for controlling an RGB LED connected to an Arduino.
 * It supports brightness control and setting colors using RGB components or hexadecimal values.
 */
#ifndef BACKLIGHT_RGB_H
#define BACKLIGHT_RGB_H

#include <Arduino.h>

/**
 * @class BacklightRGB
 * @brief Class for controlling RGB LEDs.
 * @note This class allows for easy control of common anode RGB LEDs by providing methods for setting color,
 * adjusting brightness.
 */
class BacklightRGB {
  private:
  bool _COMMON_ANODE;             ///< True if common anode RGB LED
  int _redPin;                    ///< Pin connected to the red LED.
  int _greenPin;                  ///< Pin connected to the green LED.
  int _bluePin;                   ///< Pin connected to the blue LED.
  int _brightness = 255;          ///< Brightness value (0 to 255).
  int _currentColor[3];           ///< Array storing the current RGB values.

  /**
   * @brief Adjusts the intensity of a color component based on brightness and configuration.
   * @param color Original color component value (0 to 255).
   * @return Adjusted color value.
   */
  int setColor(int color);

  /**
   * @brief Updates the RGB LED with the specified red, green, and blue values.
   * @param red Red value (0 to 255).
   * @param green Green value (0 to 255).
   * @param blue Blue value (0 to 255).
   */
  void showRGB(int red, int green, int blue);

  public:
  /**
   * @brief Constructor to initialize RGB pins.
   * @param redPin Pin connected to the red LED.
   * @param greenPin Pin connected to the green LED.
   * @param bluePin Pin connected to the blue LED.
   * @note common anode configuration by default
   */
  BacklightRGB(int redPin, int greenPin, int bluePin);

  /**
   * @brief Constructor to initialize RGB pins.
   * @param redPin Pin connected to the red LED.
   * @param greenPin Pin connected to the green LED.
   * @param bluePin Pin connected to the blue LED.
   * @param COMMON_ANODE Boolean variable indicating common anode RGB LED.
   */
  BacklightRGB(int redPin, int greenPin, int bluePin, bool COMMON_ANODE);

  /**
   * @brief Initializes the RGB LED pins as outputs.
   */
  void begin();

  /**
   * @brief Sets the brightness of the LED.
   * @param brightness Brightness value (0 to 255).
   */
  void setBrightness(int brightness);

  /**
   * @brief Sets the RGB color using an array.
   * @param rgb Array containing red, green, and blue values.
   */
  void setRGB(const int rgb[3]);

  /**
   * @brief Sets the RGB color and brightness using an array.
   * @param rgb Array containing red, green, and blue values.
   * @param brightness Brightness value (0 to 255).
   */
  void setRGB(const int rgb[3], int brightness);

  /**
   * @brief Sets the RGB color using red, green, and blue values.
   * @param red Red value (0 to 255).
   * @param green Green value (0 to 255).
   * @param blue Blue value (0 to 255).
   */
  void setRGB(int red, int green, int blue);

  /**
   * @brief Sets the RGB color and brightness using red, green, and blue values.
   * @param red Red value (0 to 255).
   * @param green Green value (0 to 255).
   * @param blue Blue value (0 to 255).
   * @param brightness Brightness value (0 to 255).
   */
  void setRGB(int red, int green, int blue, int brightness);

  /**
   * @brief Sets the RGB color using a hexadecimal value.
   * @param hexColor 24-bit hexadecimal value representing the color (e.g., 0xRRGGBB).
   */
  void setRGB(uint32_t hexColor);

  /**
   * @brief Sets the RGB color and brightness using a hexadecimal value.
   * @param hexColor 24-bit hexadecimal value representing the color (e.g., 0xRRGGBB).
   * @param brightness Brightness value (0 to 255).
   */
  void setRGB(uint32_t hexColor, int brightness);
};

#endif
