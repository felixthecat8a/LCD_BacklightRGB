/**
 * @file BacklightColors.h
 * @brief Declaration of the BacklightColors struct, providing predefined RGB color constants.
 *
 * The BacklightColors struct contains static constants representing various colors in the RGB color space.
 * Each color is defined as an array of three integers, corresponding to the red, green, and blue components.
 */

#ifndef BACKLIGHT_COLORS_H
#define BACKLIGHT_COLORS_H

#include <stdint.h>  ///< For uint8_t

/**
 * @class BacklightColors
 * @brief A collection of predefined RGB color constants.
 *
 * Each color is represented as an array of three integers, where:
 * - The first element represents the red intensity (0 to 255).
 * - The second element represents the green intensity (0 to 255).
 * - The third element represents the blue intensity (0 to 255).
 */
class BacklightColors {
  public:
    static const uint8_t BLACK[3];     ///< Black color (0, 0, 0).
    static const uint8_t WHITE[3];     ///< White color (255, 255, 255).
    static const uint8_t HOTPINK[3];   ///< Hot Pink color (255, 10, 127).
    static const uint8_t RED[3];       ///< Red color (255, 10, 10).
    static const uint8_t ORANGE[3];    ///< Orange color (255, 127, 10).
    static const uint8_t YELLOW[3];    ///< Yellow color (255, 255, 10).
    static const uint8_t LIME[3];      ///< Lime Green color (127, 255, 10).
    static const uint8_t GREEN[3];     ///< Green color (10, 255, 10).
    static const uint8_t SPRING[3];    ///< Spring color (10, 255, 127).
    static const uint8_t CYAN[3];      ///< Cyan color (10, 255, 255).
    static const uint8_t SKY[3];       ///< Sky Blue color (10, 127, 255).
    static const uint8_t BLUE[3];      ///< Blue color (10, 10, 255).
    static const uint8_t VIOLET[3];    ///< Violet color (127, 10, 255).
    static const uint8_t MAGENTA[3];   ///< Magenta color (255, 10, 255).
    static const uint8_t GRAY[3];      ///< Gray color (128, 128, 128).
    static const uint8_t GREY[3];      ///< Grey color (128, 128, 128).
    static const uint8_t OLIVE[3];     ///< Olive color (128, 128, 10).
    static const uint8_t TEAL[3];      ///< Teal color (10, 128, 128).
    static const uint8_t PURPLE[3];    ///< Purple color (128, 10, 128).
};

#endif
