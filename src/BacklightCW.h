// BacklightCW.h
#ifndef BACKLIGHT_CW_H
#define BACKLIGHT_CW_H

#include <Arduino.h>

class BacklightCW {
  private:
    int _rgb[3] = {255, 0, 0};
    int* getColorWheelRGB(int index) {
      index = index % 256;
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
        index = 0;
      }
      return getColorWheelRGB(index);
    }
};

#endif
