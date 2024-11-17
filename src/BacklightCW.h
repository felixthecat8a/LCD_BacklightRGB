// BacklightCW.h
#ifndef BACKLIGHT_CW_H
#define BACKLIGHT_CW_H

#include <Arduino.h>

class BacklightCW {
  private:
  int _index;
  int _rgb[3] = {255, 0, 0};
  const int* getColorWheelRGB(int index) {
    index = index % 256;  // Ensure index is within 0-255
    if (index < 85) {
      _rgb[0] = 255 - index * 3; _rgb[1] = index * 3; _rgb[2] = 0; // Red to Green
    } else if (index < 170) {
      index -= 85;
      _rgb[0] = 0; _rgb[1] = 255 - index * 3; _rgb[2] = index * 3; // Green to Blue
    } else {
      index -= 170;
      _rgb[0] = index * 3; _rgb[1] = 0; _rgb[2] = 255 - index * 3; // Blue to Red
    }
    return _rgb;
  }

  public:
  const int* mapToColorWheel(int value, int fromValue, int toValue) {
    int min = 0, max = 255;
    if (fromValue < toValue) {
      value = constrain(value, fromValue, toValue);
      _index = map(value, fromValue, toValue, min, max);
    } else if (fromValue > toValue) {
      value = constrain(value, toValue, fromValue);
      _index = map(value, fromValue, toValue, max, min);
    } else {
      _index = 0;
    }
    return getColorWheelRGB(_index);
  }
};

#endif
