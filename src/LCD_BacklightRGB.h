/**
 * @file LCD_BacklightRGB.h
 * @brief Declaration of the LCD_BacklightRGB class for controlling an RGB backlight.
 * The LCD_BacklightRGB class provides methods for controlling RGB LEDs, including 
 * setting colors, adjusting brightness, and using predefined color presets.
 */

#ifndef LCD_BACKLIGHTRGB_H
#define LCD_BACKLIGHTRGB_H

#include <Arduino.h>
#include "BacklightColors.h"
#include "BacklightRGB.h"
#include "BacklightCW.h"

/**
  * @class LCD_BacklightRGB
  * @brief A class to control an RGB backlight with various color and brightness options.
  */
class LCD_BacklightRGB {
private:
  BacklightRGB rgb; ///< RGB object for managing LED pins and colors.
  BacklightCW cw;   ///< Color wheel object for mapping values to colors.

public:
  /**
   * @brief Constructor for the BacklightRGB class.
   * @param r Pin number for the red LED.
   * @param g Pin number for the green LED.
   * @param b Pin number for the blue LED.
   */
  LCD_BacklightRGB(int r, int g, int b);

  /**
   * @brief Initializes the RGB backlight hardware.
   */
  void begin();

  /**
   * @brief Sets the brightness of the backlight.
   * @param brightness Brightness level (0 to 255).
   */
  void setBrightness(int brightness);

  /**
   * @brief Sets the RGB color using individual color components.
   * @param red Red intensity (0 to 255).
   * @param green Green intensity (0 to 255).
   * @param blue Blue intensity (0 to 255).
   */
  void setRGB(int red, int green, int blue);

  /**
   * @brief Sets the RGB color and brightness using individual components.
   * @param red Red intensity (0 to 255).
   * @param green Green intensity (0 to 255).
   * @param blue Blue intensity (0 to 255).
   * @param brightness Brightness level (0 to 255).
   */
  void setRGB(int red, int green, int blue, int brightness);

  /**
   * @brief Sets the RGB color using a hexadecimal color value.
   * @param hexColor Hexadecimal representation of the color (e.g., 0xFF0000 for red).
   */
  void setRGB(uint32_t hexColor);

  /**
   * @brief Sets the RGB color and brightness using a hexadecimal color value.
   * @param hexColor Hexadecimal representation of the color (e.g., 0xFF0000 for red).
   * @param brightness Brightness level (0 to 255).
   */
  void setRGB(uint32_t hexColor, int brightness);

  /**
   * @brief Sets the values to (0, 0, 0).
   */
  void off();

  /**
   * @brief Predefined color setters with optional brightness levels.
   */
  void setWhite();
  void setWhite(int brightness);
  void setPink();
  void setPink(int brightness);
  void setRed();
  void setRed(int brightness);
  void setOrange();
  void setOrange(int brightness);
  void setYellow();
  void setYellow(int brightness);
  void setLimeGreen();
  void setLimeGreen(int brightness);
  void setGreen();
  void setGreen(int brightness);
  void setTeal();
  void setTeal(int brightness);
  void setCyan();
  void setCyan(int brightness);
  void setSkyBlue();
  void setSkyBlue(int brightness);
  void setBlue();
  void setBlue(int brightness);
  void setPurple();
  void setPurple(int brightness);
  void setMagenta();
  void setMagenta(int brightness);

  /**
   * @brief Maps a value to a color on the color wheel.
   * @param value The input value to map.
   * @param fromValue The minimum range of the input value.
   * @param toValue The maximum range of the input value.
   */
  void scaleColor(int value, int fromValue, int toValue);
};

#endif
