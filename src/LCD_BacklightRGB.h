/**
 * @file LCD_BacklightRGB.h
 * @brief Declaration of the LCD_BacklightRGB class.
 * @note The LCD_BacklightRGB class provides methods for setting colors and
 * adjusting brightness of the RGB backlight on 18-pin RGB LCD modules.
 */

#ifndef LCD_BACKLIGHTRGB_H
#define LCD_BACKLIGHTRGB_H

#include <Arduino.h>

#include "BacklightColors.h"
#include "BacklightRGB.h"

/**
 * @class LCD_BacklightRGB
 * @brief A class for crontrolling RGB pins on RGB LCD modules
 * @note The LCD_BacklightRGB class provides methods for setting colors and
 * adjusting brightness of the RGB backlight on 18-pin RGB LCD modules.
 */
class LCD_BacklightRGB {
  private:
    BacklightRGB rgb; ///< RGB object for managing LED pins and colors.

  public:
    /**
     * @brief Constructor for the BacklightRGB class.
     * @param r Pin for the red LED.
     * @param g Pin for the green LED.
     * @param b Pin for the blue LED.
     */
    LCD_BacklightRGB(int r, int g, int b);

    /**
     * @brief Constructor for the BacklightRGB class.
     * @param r Pin for the red LED.
     * @param g Pin for the green LED.
     * @param b Pin for the blue LED.
     * @param isCommonAnode Boolean variable indicating common anode RGB LED.
     */
    LCD_BacklightRGB(int r, int g, int b, bool isCommonAnode);

    /**
     * @brief Initializes the RGB backlight.
     * @note Sets the initial color to a default teal (hex: 0x0A878F).
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
    int getBrightness() const;

    /**
     * @brief Sets RGB color using individual color components.
     * @param red Red intensity (0 to 255).
     * @param green Green intensity (0 to 255).
     * @param blue Blue intensity (0 to 255).
     */
    void setRGB(int red, int green, int blue);

    /**
     * @brief Sets RGB color using individual color components and brightness.
     * @param red Red intensity (0 to 255).
     * @param green Green intensity (0 to 255).
     * @param blue Blue intensity (0 to 255).
     * @param brightness Brightness level (0 to 255).
     */
    void setRGB(int red, int green, int blue, int brightness);

    /**
     * @brief Returns the current RGB values.
     * @return Pointer to an array of 3 uint8_t values {R, G, B}.
     */
    const int* getRGB() const;

    /**
     * @brief Sets the RGB color using a hexadecimal color value.
     * @param hexColor Hexadecimal representation of the color
     * @example setRGB(0xFF0000)
     */
    void setHex(uint32_t hexColor);

    /**
     * @brief Sets the RGB color and brightness using a hexadecimal color value.
     * @param hexColor Hexadecimal representation of the color.
     * @param brightness Brightness level (0 to 255).
     */
    void setHex(uint32_t hexColor, int brightness);

    /**
     * @brief Sets the RGB LED color using HSV (Hue, Saturation, Value).
     * @param hue The hue value (0-360 degrees).
     * @param sat The saturation level (0.0-1.0).
     * @param val The brightness value (0.0-1.0).
     */
    void setHSV(int hue, float sat = 1.0, float val= 1.0);

    /**
     * @brief Sets
     * @param cyan Cyan value (0.0-1.0)
     * @param magenta Magenta value (0.0-1.0)
     * @param yellow Yellow value (0.0-1.0)
     * @param key Key value (0.0-1.0)
     */
    void setCMYK(float cyan, float magenta, float yellow, float key);

    /**
     * @brief Sets the values to (0, 0, 0).
     */
    void off();

    /**
     * @brief Predefined color methods for setting specific colors.
     * @note Colors include white, pink, red, orange, yellow, lime green, green,
     * spring green, cyan, sky blue, blue, purple, magenta, and white.
     * @note Brightness can also be set for each color.
     */
    /// @{
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
    void setSpringGreen();
    void setSpringGreen(int brightness);
    void setCyan();
    void setCyan(int brightness);
    void setSkyBlue();
    void setSkyBlue(int brightness);
    void setBlue();
    void setBlue(int brightness);
    void setViolet();
    void setViolet(int brightness);
    void setMagenta();
    void setMagenta(int brightness);
    void setGray();
    void setGray(int brightness);
    void setOlive();
    void setOlive(int brightness);
    void setTeal();
    void setTeal(int brightness);
    void setPurple();
    void setPurple(int brightness);
    /// @}

    /**
     * @brief Maps a value to a color on the color wheel.
     * @param value The input value to map.
     * @param fromValue The minimum range of the input value.
     * @param toValue The maximum range of the input value.
     */
    void scaleColor(int value, int fromValue, int toValue);

};

#endif
