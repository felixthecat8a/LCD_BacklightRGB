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
    static const uint8_t RED[3];       ///< Red color (255, 10, 10).
    static const uint8_t VERMILION[3];  ///< Vermilion color (255, 64, 10).
    static const uint8_t ORANGE[3];    ///< Orange color (255, 127, 10).
    static const uint8_t AMBER[3];     ///< Amber color (255, 191, 10).
    static const uint8_t YELLOW[3];    ///< Yellow color (255, 255, 10).
    static const uint8_t LIME[3];      ///< Lime Green color (191, 255, 0).
    static const uint8_t CHARTREUSE[3];///< Chartreuse color (128, 255, 0).
    static const uint8_t HARLEQUIN[3]; ///< Harlequin color (64, 255, 0).
    static const uint8_t GREEN[3];     ///< Green color (0, 255, 0).
    static const uint8_t MINT[3];      ///< Mint color (0, 255, 64).
    static const uint8_t SPRING[3];    ///< Spring Green color (0, 255, 128).
    static const uint8_t TURQUOISE[3]; ///< Turquoise color (0, 255, 191).
    static const uint8_t CYAN[3];      ///< Cyan color (0, 255, 255).
    static const uint8_t SKY[3];       ///< Sky Blue color (0, 191, 255).
    static const uint8_t AZURE[3];     ///< Azure color (0, 128, 255).
    static const uint8_t CERULEAN[3];  ///< Cerulean color (0, 64, 255).
    static const uint8_t BLUE[3];      ///< Blue color (0, 0, 255).
    static const uint8_t INDIGO[3];    ///< Indigo color (64, 0, 255).
    static const uint8_t VIOLET[3];    ///< Violet color (128, 0, 255).
    static const uint8_t PURPLE[3];    ///< Purple color (191, 0, 255).
    static const uint8_t MAGENTA[3];   ///< Magenta color (255, 0, 255).
    static const uint8_t HOTPINK[3];   ///< Hot Pink color (255, 0, 191).
    static const uint8_t ROSE[3];      ///< Rose color (255, 0, 128).
    static const uint8_t CRIMSON[3];   ///< Crimson color (255, 0, 64).

    static const uint8_t GRAY[3];      ///< Gray color (128, 128, 128).
    static const uint8_t GREY[3];      ///< Grey color (128, 128, 128).
    static const uint8_t OLIVE[3];     ///< Olive color (128, 128, 10).
    static const uint8_t TEAL[3];      ///< Teal color (10, 128, 128).
};

#endif
