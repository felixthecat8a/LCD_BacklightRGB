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
     * @brief Calculates the RGB color for a given index on the color wheel.
     *
     * @param index Index on the color wheel (0 to 255).
     * @return Pointer to the array containing RGB values.
     *
     * The index is divided into three segments:
     * - 0 to 84: Transition from Red to Green.
     * - 85 to 169: Transition from Green to Blue.
     * - 170 to 255: Transition from Blue to Red.
     */
    int* getColorWheelRGB(int index) {
      index = index % 256; // Ensure index wraps within 0-255.
      if (index < 85) {
        // Red to Green
        _rgb[0] = 255 - index * 3;
        _rgb[1] = index * 3;
        _rgb[2] = 0;
      } else if (index < 170) {
        // Green to Blue
        index -= 85;
        _rgb[0] = 0;
        _rgb[1] = 255 - index * 3;
        _rgb[2] = index * 3;
      } else {
        // Blue to Red
        index -= 170;
        _rgb[0] = index * 3;
        _rgb[1] = 0;
        _rgb[2] = 255 - index * 3;
      }
      return _rgb;
    }

  public:
    /**
     * @brief Maps a value to the RGB color wheel based on the input range.
     *
     * @param value The input value to be mapped.
     * @param fromValue The lower bound of the input range.
     * @param toValue The upper bound of the input range.
     * @return Pointer to the array containing RGB values.
     *
     * If `fromValue` is less than `toValue`, the mapping progresses from 0 to 255 on the color wheel.
     * If `fromValue` is greater than `toValue`, the mapping reverses from 255 to 0 on the color wheel.
     * If `fromValue` equals `toValue`, the color defaults to Red (index 0 on the color wheel).
     */
    int* mapToColorWheel(int value, int fromValue, int toValue) {
      int index;
      const int min = 0, max = 255;
      if (fromValue < toValue) {
        value = constrain(value, fromValue, toValue);
        index = map(value, fromValue, toValue, min, max);
      } else if (fromValue > toValue) {
        value = constrain(value, toValue, fromValue);
        index = map(value, fromValue, toValue, max, min);
      } else {
        index = 0; // Default to the first color if range is invalid.
      }
      return getColorWheelRGB(index);
    }
};

#endif