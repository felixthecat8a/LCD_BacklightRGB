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

/**
  * @class LCD_BacklightRGB
  * @brief A class to control an RGB backlight with various color and brightness options.
  */
class LCD_BacklightRGB {
  private:
    BacklightRGB rgb; ///< RGB object for managing LED pins and colors.

  public:
    /**
     * @brief Constructor for the BacklightRGB class.
     * @param r Pin number for the red LED.
     * @param g Pin number for the green LED.
     * @param b Pin number for the blue LED.
     */
    LCD_BacklightRGB(int r, int g, int b);

    /**
     * @brief Constructor for the BacklightRGB class.
     * @param r Pin number for the red LED.
     * @param g Pin number for the green LED.
     * @param b Pin number for the blue LED.
     * @param isCommonAnode Boolean variable indicating common anode RGB LED.
     */
    LCD_BacklightRGB(int r, int g, int b, bool isCommonAnode);

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
     * @brief Gets the current brightness level.
     * @return Brightness value (0 to 255).
     */
    int getBrightness();

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
     * @brief Sets the RGB LED color using HSV (Hue, Saturation, Value).
     * @param hue The hue value (0-360 degrees).
     * @param sat The saturation level (0.0-1.0).
     * @param val The brightness value (0.0-1.0).
     */
    void setHSV(int hue, float sat = 1.0, float val= 1.0);

    /**
     * @brief Sets the values to (0, 0, 0).
     */
    void off() {
      rgb.setRGB(BacklightColors::BLACK);
    }

    /**
     * @brief Predefined color methods for setting specific colors with optional brightness.
     * @note Colors include pink, red, orange, yellow, lime green, green, spring green, cyan,
     * sky blue, blue, purple, magenta, and white.
     * @note Brightness can also be set for each color.
     */
    void setWhite() { rgb.setRGB(BacklightColors::WHITE); }
    void setWhite(int brightness) {
      rgb.setRGB(BacklightColors::WHITE, brightness);
    }

    void setPink() { rgb.setRGB(BacklightColors::HOTPINK); }
    void setPink(int brightness) {
      rgb.setRGB(BacklightColors::HOTPINK, brightness);
    }

    void setRed() { rgb.setRGB(BacklightColors::RED); }
    void setRed(int brightness) {
      rgb.setRGB(BacklightColors::RED, brightness);
    }

    void setOrange() { rgb.setRGB(BacklightColors::ORANGE); }
    void setOrange(int brightness) {
      rgb.setRGB(BacklightColors::ORANGE, brightness);
    }

    void setYellow() { rgb.setRGB(BacklightColors::YELLOW); }
    void setYellow(int brightness) {
      rgb.setRGB(BacklightColors::YELLOW, brightness);
    }

    void setLimeGreen() { rgb.setRGB(BacklightColors::LIME); }
    void setLimeGreen(int brightness) {
      rgb.setRGB(BacklightColors::LIME, brightness);
    }

    void setGreen() { rgb.setRGB(BacklightColors::GREEN); }
    void setGreen(int brightness) {
      rgb.setRGB(BacklightColors::GREEN, brightness);
    }

    void setSpringGreen() { rgb.setRGB(BacklightColors::SPRING); }
    void setSpringGreen(int brightness) {
      rgb.setRGB(BacklightColors::SPRING, brightness);
    }

    void setCyan() { rgb.setRGB(BacklightColors::CYAN); }
    void setCyan(int brightness) {
      rgb.setRGB(BacklightColors::CYAN, brightness);
    }

    void setSkyBlue() { rgb.setRGB(BacklightColors::SKY); }
    void setSkyBlue(int brightness) {
      rgb.setRGB(BacklightColors::SKY, brightness);
    }

    void setBlue() { rgb.setRGB(BacklightColors::BLUE); }
    void setBlue(int brightness) {
      rgb.setRGB(BacklightColors::BLUE, brightness);
    }

    void setViolet() { rgb.setRGB(BacklightColors::VIOLET); }
    void setViolet(int brightness) {
      rgb.setRGB(BacklightColors::VIOLET, brightness);
    }

    void setMagenta() { rgb.setRGB(BacklightColors::MAGENTA); }
    void setMagenta(int brightness) {
      rgb.setRGB(BacklightColors::MAGENTA, brightness);
    }

    void setGray() { rgb.setRGB(BacklightColors::GRAY); }
    void setGray(int brightness) {
      rgb.setRGB(BacklightColors::GRAY, brightness);
    }

    void setOlive() { rgb.setRGB(BacklightColors::OLIVE); }
    void setOlive(int brightness) {
      rgb.setRGB(BacklightColors::OLIVE, brightness);
    }

    void setTeal() { rgb.setRGB(BacklightColors::TEAL); }
    void setTeal(int brightness) {
      rgb.setRGB(BacklightColors::TEAL, brightness);
    }

    void setPurple() { rgb.setRGB(BacklightColors::PURPLE); }
    void setPurple(int brightness) {
      rgb.setRGB(BacklightColors::PURPLE, brightness);
    }

    /**
     * @brief Maps a value to a color on the color wheel.
     * @param value The input value to map.
     * @param fromValue The minimum range of the input value.
     * @param toValue The maximum range of the input value.
     */
    void scaleColor(int value, int fromValue, int toValue) {
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
};

#endif
