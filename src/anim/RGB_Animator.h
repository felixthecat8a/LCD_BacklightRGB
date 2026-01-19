/**
 * @file RGB_Animator.h
 * @brief Handles non-blocking color transitions and effects for LCD_BacklightRGB.
 */

#ifndef RGB_ANIMATOR_H
#define RGB_ANIMATOR_H

#include <Arduino.h>

class LCD_BacklightRGB; // *Forward declaration to avoid circular include

class RGB_Animator {
  private:
    LCD_BacklightRGB* _target;  ///< Target backlight instance.
    uint32_t _startColor;       ///< Starting color for animation.
    uint32_t _endColor;         ///< Ending color for animation.
    uint32_t _startTime;        ///< Start timestamp (millis).
    uint32_t _duration;         ///< Duration in milliseconds.
    bool _active;               ///< Whether an animation is currently active.

    float _easeInOut(float t) const; ///< Easing function for smooth fades.

    uint8_t _r1, _g1, _b1;
    uint8_t _r2, _g2, _b2;

  public:
    RGB_Animator();

    /**
     * @brief Attaches the animator to a target LCD_BacklightRGB instance.
     * @param target Pointer to the backlight object.
     */
    void attach(LCD_BacklightRGB* target);

    /**
     * @brief Starts a non-blocking fade animation to a new color.
     * @param color Target color (hexadecimal format, e.g., 0xFF6600).
     * @param duration Duration in milliseconds.
     */
    void fadeTo(uint32_t color, uint32_t duration);

    /**
     * @brief Updates the animation state.
     * @note Should be called frequently in the main loop.
     */
    void update();

    /**
     * @brief Stops the current animation immediately.
     */
    void stop();

    /**
     * @brief Returns whether an animation is currently running.
     * @return True if an animation is active.
     */
    bool isActive() const;

    /**
     * @brief Creates a pulsing "breathe" effect.
     * @param color The base color to pulse.
     * @param period Total time (in ms) for one pulse cycle.
     */
    void breathe(uint32_t color, uint32_t period = 2000);

    /**
     * @brief Creates a smooth rainbow animation cycling through all hues.
     * @param cycleTime Duration (in ms) for one full color rotation.
     * @note This effect uses HSV hue cycling for smooth rainbow transitions.
     */
    void rainbow(uint32_t cycleTime = 5000);

    /**
     * @brief Creates a smooth pulsing effect between two colors.
     * @param color1 Starting color in hex (0xRRGGBB).
     * @param color2 Ending color in hex (0xRRGGBB).
     * @param duration Time (in ms) for one full pulse cycle.
     */
    void pulse(uint32_t color1, uint32_t color2, uint32_t duration);

};

#endif
