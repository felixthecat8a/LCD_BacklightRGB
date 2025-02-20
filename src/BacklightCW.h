/**
 * @file BacklightCW.h
 * @brief Header file for the BacklightCW class.
 *
 * The `BacklightCW` (Backlight Color Wheel) class provides functionality to map a value
 * within a given range to a color on a circular RGB color wheel. This is useful for
 * visualizing values with smooth color transitions.
 */

#ifndef BACKLIGHT_CW_H
#define BACKLIGHT_CW_H

#include <Arduino.h>

/**
 * @class BacklightCW
 * @brief A utility class for mapping values to the RGB color wheel.
 *
 * This class maps a numeric value from a specified range to a corresponding RGB color on a circular color wheel.
 * It ensures smooth transitions between Red, Green, and Blue.
 */
class BacklightCW {
  private:
    int _rgb[3] = {255, 0, 0};  ///< Array to store the current RGB color.

    /**
     * @brief Converts HSV to RGB.
     *
     * @param h Hue (0-360 degrees).
     * @param s Saturation (0-1).
     * @param v Value/Brightness (0-1).
     */
    void hsvToRgb(int h, float s, float v) {
        float c = v * s;
        float x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
        float m = v - c;

        float r, g, b;
        if (h < 60) {
          r = c, g = x, b = 0;
        } else if (h < 120) {
          r = x, g = c, b = 0;
        } else if (h < 180) {
          r = 0, g = c, b = x;
        } else if (h < 240) {
          r = 0, g = x, b = c;
        } else if (h < 300) {
          r = x, g = 0, b = c;
        } else {
          r = c, g = 0, b = x;
        }

        _rgb[0] = (r + m) * 255;
        _rgb[1] = (g + m) * 255;
        _rgb[2] = (b + m) * 255;
    }

  public:
    /**
     * @brief Maps a value to the RGB color wheel based on HSV.
     *
     * @param value The input value to be mapped.
     * @param fromValue The lower bound of the input range.
     * @param toValue The upper bound of the input range.
     * @return Pointer to the array containing RGB values.
     */
    int* mapToColorWheel(int value, int fromValue, int toValue) {
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
        hsvToRgb(hue, 1.0, 1.0); // Full saturation and brightness
        return _rgb;
    }
};

#endif
