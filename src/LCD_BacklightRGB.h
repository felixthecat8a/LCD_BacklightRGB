// LCD_BacklightRGB.h
#ifndef LCD_BACKLIGHTRGB_H
#define LCD_BACKLIGHTRGB_H

#include <Arduino.h>

class LCD_BacklightRGB {
private:
  int _redPin, _greenPin, _bluePin;
  int _brightness;
  int _currentColor[3];
  void showRGB(int red, int green, int blue);
  int setColor(int color);

public:
  LCD_BacklightRGB(int redPin, int greenPin, int bluePin);
  void begin();
  void setRGB(const int rgb[3]);
  void setRGB(const int rgb[3], int brightness);
  void setRGB(int red, int green, int blue);
  void setRGB(int red, int green, int blue, int brightness);
  void setBrightness(int brightness);
  void setWhite();
  void setWhite(int brightness);
  void setRed();
  void setRed(int brightness);
  void setOrange();
  void setOrange(int brightness);
  void setYellow();
  void setYellow(int brightness);
  void setLimeGreen();
  void setLimeGreen(int brightness);
  void setGreen();
  void setGreen(int brightness);
  void setTeal();
  void setTeal(int brightness);
  void setCyan();
  void setCyan(int brightness);
  void setSkyBlue();
  void setSkyBlue(int brightness);
  void setBlue();
  void setBlue(int brightness);
  void setPurple();
  void setPurple(int brightness);
  void setMagenta();
  void setMagenta(int brightness);
  void setPink();
  void setPink(int brightness);
  void off();
};

#endif
