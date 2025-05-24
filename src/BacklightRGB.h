/**
 * @file BacklightRGB.h
 * @brief Header file for the BacklightRGB class.
 *
 * @note The BacklightRGB class provides an interface for controlling an RGB LED
 * connected to an Arduino. It supports brightness control and setting colors using
 * RGB components or hexadecimal values.
 */
#ifndef BACKLIGHT_RGB_H
#define BACKLIGHT_RGB_H

#include <Arduino.h>

/**
 * @class BacklightRGB
 * @brief Class for controlling RGB LEDs.
 * @note This class allows for easy control of common anode RGB LEDs by providing
 * methods for setting color and adjusting brightness.
 */
class BacklightRGB {
    private:
    bool _COMMON_ANODE;     ///< True if common anode RGB LED
    int _redPin;            ///< Pin connected to the red LED.
    int _greenPin;          ///< Pin connected to the green LED.
    int _bluePin;           ///< Pin connected to the blue LED.
    int _brightness;  ///< Brightness value (0 to 255).
    int _currentColor[3];   ///< Array storing the current RGB values.

    /**
     * @brief Adjusts the intensity of a color component based on brightness.
     * @param color Original color component value (0 to 255).
     * @return Adjusted color value.
     */
    inline int setColor(int color);

    /**
     * @brief Updates the RGB LED with the specified red, green, and blue values.
     * @param red Red value (0 to 255)
     * @param green Green value (0 to 255)
     * @param blue Blue value (0 to 255)
     */
    inline void showRGB(int red, int green, int blue);

    public:
    /**
     * @brief Constructor to initialize RGB pins.
     * @param redPin Pin connected to red LED
     * @param greenPin Pin connected to green LED
     * @param bluePin Pin connected to blue LED
     * @note common anode configuration by default
     */
    BacklightRGB(int redPin, int greenPin, int bluePin);

    /**
     * @brief Constructor to initialize RGB pins.
     * @param redPin Pin connected to red LED
     * @param greenPin Pin connected to green LED
     * @param bluePin Pin connected to blue LED
     * @param COMMON_ANODE Boolean variable indicating common anode RGB LED.
     */
    BacklightRGB(int redPin, int greenPin, int bluePin, bool COMMON_ANODE);

    /**
     * @brief Initializes the RGB LED pins as outputs or PWM channels for ESP32.
     */
    void begin();

    /**
     * @brief Deleted copy constructor to prevent copying of BacklightRGB instances.
     * @note Copying is disallowed to avoid issues with shared hardware resources (e.g., PWM pins).
     */
    BacklightRGB(const BacklightRGB&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying of BacklightRGB instances.
     * @note Copying is disallowed to avoid unintended behavior from sharing pin assignments.
     */
    BacklightRGB& operator=(const BacklightRGB&) = delete;

    /**
     * @brief Sets the brightness of the LED.
     * @param brightness Brightness value (0 to 255).
     */
    void setBrightness(int brightness);

    /**
     * @brief Gets the current brightness level.
     * @return Brightness value (0 to 255).
     */
    int getBrightness() const;

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
     * @param red Red value (0 to 255)
     * @param green Green value (0 to 255)
     * @param blue Blue value (0 to 255)
     */
    void setRGB(int red, int green, int blue);

    /**
     * @brief Sets the RGB color and brightness using red, green, and blue values.
     * @param red Red value (0 to 255)
     * @param green Green value (0 to 255)
     * @param blue Blue value (0 to 255)
     * @param brightness Brightness value (0 to 255)
     */
    void setRGB(int red, int green, int blue, int brightness);

    /**
     * @brief Sets the RGB color using a hexadecimal value.
     * @param hexColor 24-bit hexadecimal value representing the color.
     */
    void setHex(uint32_t hexColor);

    /**
     * @brief Sets the RGB color and brightness using a hexadecimal value.
     * @param hexColor 24-bit hexadecimal value representing the color.
     * @param brightness Brightness value (0 to 255).
     */
    void setHex(uint32_t hexColor, int brightness);

    /**
     * @brief Gets the current RGB color.
     * @return Pointer to an array containing red, green, and blue values.
     */
    const int* getRGB() const;

    /**
     * @brief Gets the current color as a 24-bit hexadecimal value.
     * @return 24-bit integer representing the color (0xRRGGBB).
     */
    uint32_t getColorHex() const;

    /**
     * @brief Sets the RGB LED color using HSV (Hue, Saturation, Value).
     * @param hue Hue value (0-360 degrees)
     * @param sat Saturation level (0.0-1.0)
     * @param val Brightness value (0.0-1.0)
     */
    void setHSV(int hue, float sat = 1.0, float val= 1.0);

    /**
     * @brief Sets the RGB LED color using CMYK (Cyan, Magenta, Yellow, Key).
     * @param cyan Cyan value (0.0-1.0)
     * @param magenta Magenta value (0.0-1.0)
     * @param yellow Yellow value (0.0-1.0)
     * @param key Key value (0.0-1.0)
     */
    void setCMYK(float cyan, float magenta, float yellow, float key);

};

#endif
