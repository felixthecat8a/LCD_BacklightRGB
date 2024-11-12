// RGB.h
#ifndef RGB_H
#define RGB_H

#include <Arduino.h>

class RGB {
  private:
  const bool COMMON_ANODE = true;
  int _redPin, _greenPin, _bluePin;
  int _brightness = 255;
  int _currentColor[3];
  int setColor(int color);
  void showRGB(int red, int green, int blue);
  
  public:
  RGB(int redPin, int greenPin, int bluePin);
  void begin();
  void setBrightness(int brightness);
  void setRGB(const int rgb[3]);
  void setRGB(const int rgb[3], int brightness);
  void setRGB(int red, int green, int blue);
  void setRGB(int red, int green, int blue, int brightness);
};

#endif