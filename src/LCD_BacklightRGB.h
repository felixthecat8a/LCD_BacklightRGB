/**
 * @file LCD_BacklightRGB.h
 * @brief Declaration of the LCD_BacklightRGB class.
 * @note The LCD_BacklightRGB class provides methods for setting colors and
 * adjusting brightness of the RGB backlight on 18-pin RGB LCD modules.
 */

#ifndef LCD_BACKLIGHTRGB_H
#define LCD_BACKLIGHTRGB_H

#include <Arduino.h>
#include <LiquidCrystal.h>

#include "util/BacklightColors.h"
#include "util/BacklightRGB.h"

/**
 * @class LCD_BacklightRGB
 * @brief A class for controlling RGB pins on RGB LCD modules
 * @note The LCD_BacklightRGB class provides methods for setting colors and
 * adjusting brightness of the RGB backlight on 18-pin RGB LCD modules.
 */
class LCD_BacklightRGB {
  public:
    /**
     * @brief Constructor for the LCD_BacklightRGB class.
     * @param r Pin for the red LED.
     * @param g Pin for the green LED.
     * @param b Pin for the blue LED.
     * @param isCommonAnode Boolean variable indicating common anode RGB LED.
     */
    LCD_BacklightRGB(int r, int g, int b, bool isCommonAnode = true);

    /**
     * @brief Constructor for the LCD_BacklightRGB class with LiquidCrystal reference.
     * @param lcd Reference to a LiquidCrystal object.
     * @param r Pin for the red LED.
     * @param g Pin for the green LED.
     * @param b Pin for the blue LED.
     * @param isCommonAnode Boolean variable indicating common anode RGB LED.
     */
    LCD_BacklightRGB(LiquidCrystal& lcd, int r, int g, int b, bool isCommonAnode = true);

    /**
     * @brief Initializes the RGB backlight.
     * @note Must be called before using other methods.
     * Sets the initial color to a default teal (hex: 0x0A878F).
     */
    void begin();

    /**
     * @brief Sets whether to apply gamma correction.
     * @param enabled True to apply gamma correction.
     */
    void setGamma(bool enabled);

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
     * @brief Copies the current RGB values into the provided array.
     * @param out Array of 3 uint8_t values where the RGB values will be stored.
     */
    void getRGB(uint8_t out[3]) const;

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
     * @brief Sets the RGB color using CMYK color components.
     * @param cyan Cyan value (0.0-1.0)
     * @param magenta Magenta value (0.0-1.0)
     * @param yellow Yellow value (0.0-1.0)
     * @param key Key value (0.0-1.0)
     */
    void setCMYK(float cyan, float magenta, float yellow, float key);

    /**
     * @brief Sets the values to (0, 0, 0).
     */
    void off() { rgb.setRGB(BacklightColors::BLACK); }

    /**
     * @brief Predefined color methods for setting specific colors.
     * @note Colors include white, pink, red, orange, yellow, lime green, green,
     * spring green, cyan, sky blue, blue, purple, magenta, and white.
     */
    /// @{
    void setWhite() { rgb.setRGB(BacklightColors::WHITE); }
    void setPink() { rgb.setRGB(BacklightColors::HOTPINK); }
    void setRed() { rgb.setRGB(BacklightColors::RED); }
    void setOrange() { rgb.setRGB(BacklightColors::ORANGE); }
    void setYellow() { rgb.setRGB(BacklightColors::YELLOW); }
    void setLimeGreen() { rgb.setRGB(BacklightColors::LIME); }
    void setGreen() { rgb.setRGB(BacklightColors::GREEN); }
    void setSpringGreen() { rgb.setRGB(BacklightColors::SPRING); }
    void setCyan() { rgb.setRGB(BacklightColors::CYAN); }
    void setSkyBlue() { rgb.setRGB(BacklightColors::SKY); }
    void setBlue() { rgb.setRGB(BacklightColors::BLUE); }
    void setViolet() { rgb.setRGB(BacklightColors::VIOLET); }
    void setMagenta() { rgb.setRGB(BacklightColors::MAGENTA); }
    /// @}

    /**
     * @brief Predefined color methods for setting specific colors.
     * @param brightness Brightness level (0 to 255).
     * @note Colors include white, pink, red, orange, yellow, lime green, green,
     * spring green, cyan, sky blue, blue, magenta, and white.
     */
    /// @{
    void setWhite(int brightness);
    void setPink(int brightness);
    void setRed(int brightness);
    void setOrange(int brightness);
    void setYellow(int brightness);
    void setLimeGreen(int brightness);
    void setGreen(int brightness);
    void setSpringGreen(int brightness);
    void setCyan(int brightness);
    void setSkyBlue(int brightness);
    void setBlue(int brightness);
    void setViolet(int brightness);
    void setMagenta(int brightness);
    /// @}

    /**
     * @brief Maps a numeric value to a corresponding color across the RGB color wheel.
     * @param value The input value to map.
     * @param fromValue The minimum input range.
     * @param toValue The maximum input range.
     * @note Internally maps the range to a hue (0–360) and applies full saturation/value.
     */
    void scaleColor(int value, int fromValue, int toValue);

    /**
     * @brief Initializes the LCD display.
     * @param cols Number of columns on the LCD.
     * @param rows Number of rows on the LCD.
     */
    void lcdBegin(uint8_t cols, uint8_t rows) { if (_lcd) _lcd->begin(cols, rows);    }

    void print(const char* msg) { if (_lcd) _lcd->print(msg); }
    void print(String msg) { if (_lcd) _lcd->print(msg); }
    void print(int value) { if (_lcd) _lcd->print(value); }

    void clear() { if (_lcd) _lcd->clear(); }
    void setCursor(uint8_t col, uint8_t row) { if (_lcd) _lcd->setCursor(col, row); }
    void home() { if (_lcd) _lcd->home(); }

    void scrollDisplayLeft() { if (_lcd) _lcd->scrollDisplayLeft(); }
    void scrollDisplayRight() { if (_lcd) _lcd->scrollDisplayRight(); }

    void noDisplay() { if (_lcd) _lcd->noDisplay(); }
    void display() { if (_lcd) _lcd->display(); }

    void noCursor() { if (_lcd) _lcd->noCursor(); }
    void cursor() { if (_lcd) _lcd->cursor(); }
    void noBlink() { if (_lcd) _lcd->noBlink(); }
    void blink() { if (_lcd) _lcd->blink(); }

    void leftToRight() { if (_lcd) _lcd->leftToRight(); }
    void rightToLeft() { if (_lcd) _lcd->rightToLeft(); }
    void autoscroll() { if (_lcd) _lcd->autoscroll(); }
    void noAutoscroll() { if (_lcd) _lcd->noAutoscroll(); }

    void createChar(uint8_t location, uint8_t charmap[]) {
      if (_lcd) _lcd->createChar(location, charmap);
    }

    /**
     * @brief Gets a pointer to the underlying LiquidCrystal object.
     * @return A pointer to the LiquidCrystal object, or nullptr if not initialized.
     */
    LiquidCrystal* getLCD() { return _lcd; }

  private:
    BacklightRGB rgb; ///< RGB object for managing LED pins and colors.

    LiquidCrystal* _lcd = nullptr; ///< Pointer to the LiquidCrystal object, if provided.

};

#endif
