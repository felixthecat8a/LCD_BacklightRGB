#include "RGB_Animator.h"
#include "../LCD_BacklightRGB.h"  // *class definition

RGB_Animator::RGB_Animator()
  : _target(nullptr),
    _startColor(0),
    _endColor(0),
    _startTime(0),
    _duration(0),
    _active(false),
    _r1(0), _g1(0), _b1(0),
    _r2(0), _g2(0), _b2(0) {}

void RGB_Animator::attach(LCD_BacklightRGB* target) {
  _target = target;
}

void RGB_Animator::fadeTo(uint32_t color, uint32_t duration) {
  if (!_target) return;

  _startColor = strtoul(_target->getHexString().substring(1).c_str(), nullptr, 16);
  _endColor = color;

  _r1 = (_startColor >> 16) & 0xFF;
  _g1 = (_startColor >> 8) & 0xFF;
  _b1 = _startColor & 0xFF;

  _r2 = (color >> 16) & 0xFF;
  _g2 = (color >> 8) & 0xFF;
  _b2 = color & 0xFF;

  _startTime = millis();
  _duration = duration;
  _active = true;
}

void RGB_Animator::update() {
  if (!_active || !_target) return;

  uint32_t now = millis();
  float progress = (float)(now - _startTime) / _duration;

  if (progress >= 1.0f) {
    _target->setHex(_endColor);
    _active = false;
    return;
  }

  progress = _easeInOut(progress);

  uint8_t r = _r1 + (_r2 - _r1) * progress;
  uint8_t g = _g1 + (_g2 - _g1) * progress;
  uint8_t b = _b1 + (_b2 - _b1) * progress;

  _target->setRGB(r, g, b);
}

void RGB_Animator::stop() {
  _active = false;
}

bool RGB_Animator::isActive() const {
  return _active;
}

float RGB_Animator::_easeInOut(float t) const {
  return (t < 0.5f) ? 2.0f * t * t : 1.0f - powf(-2.0f * t + 2.0f, 2.0f) / 2.0f;
}

void RGB_Animator::breathe(uint32_t color, uint32_t period) {
  if (!_target) return;

  float phase = (millis() % period) / (float)period;
  float intensity = 0.5f - 0.5f * cosf(phase * TWO_PI);

  uint8_t r = ((color >> 16) & 0xFF) * intensity;
  uint8_t g = ((color >> 8) & 0xFF) * intensity;
  uint8_t b = (color & 0xFF) * intensity;

  _target->setRGB(r, g, b);
}

void RGB_Animator::rainbow(uint32_t cycleTime) {
  if (!_target) return;

  uint32_t now = millis();
  float hue = fmodf((now % cycleTime) * 360.0f / cycleTime, 360.0f);
  _target->setHSV((int)hue, 1.0, 1.0);
}

void RGB_Animator::pulse(uint32_t color1, uint32_t color2, uint32_t duration) {
  if (!_target) return;

  uint32_t now = millis();
  float phase = (now % duration) / (float)duration;
  float blend = 0.5f - 0.5f * cosf(phase * TWO_PI);

  uint8_t r1 = (color1 >> 16) & 0xFF;
  uint8_t g1 = (color1 >> 8) & 0xFF;
  uint8_t b1 = color1 & 0xFF;

  uint8_t r2 = (color2 >> 16) & 0xFF;
  uint8_t g2 = (color2 >> 8) & 0xFF;
  uint8_t b2 = color2 & 0xFF;

  uint8_t r = r1 + (r2 - r1) * blend;
  uint8_t g = g1 + (g2 - g1) * blend;
  uint8_t b = b1 + (b2 - b1) * blend;

  _target->setRGB(r, g, b);
}
