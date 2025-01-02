/**
 * @file BacklightColors.h
 * @brief Declaration of the BacklightColors struct, providing predefined RGB color constants.
 *
 * The BacklightColors struct contains static constants representing various colors in the RGB color space.
 * Each color is defined as an array of three integers, corresponding to the red, green, and blue components.
 */

#ifndef BACKLIGHT_COLORS_H
#define BACKLIGHT_COLORS_H

/**
 * @struct BacklightColors
 * @brief A collection of predefined RGB color constants.
 *
 * Each color is represented as an array of three integers, where:
 * - The first element represents the red intensity (0 to 255).
 * - The second element represents the green intensity (0 to 255).
 * - The third element represents the blue intensity (0 to 255).
 */
struct BacklightColors {
  static const int BLACK[3];     ///< Black color (0, 0, 0).
  static const int WHITE[3];     ///< White color (255, 255, 255).
  static const int HOTPINK[3];   ///< Hot Pink color (255, 10, 127).
  static const int RED[3];       ///< Red color (255, 10, 10).
  static const int ORANGE[3];    ///< Orange color (255, 127, 10).
  static const int YELLOW[3];    ///< Yellow color (255, 255, 10).
  static const int LIME[3];      ///< Lime Green color (127, 255, 10).
  static const int GREEN[3];     ///< Green color (10, 255, 10).
  static const int TEAL[3];      ///< Teal color (10, 255, 127).
  static const int CYAN[3];      ///< Cyan color (10, 255, 255).
  static const int SKY[3];       ///< Sky Blue color (10, 127, 255).
  static const int BLUE[3];      ///< Blue color (10, 10, 255).
  static const int PURPLE[3];    ///< Purple color (127, 10, 255).
  static const int MAGENTA[3];   ///< Magenta color (255, 10, 255).
};

#endif
