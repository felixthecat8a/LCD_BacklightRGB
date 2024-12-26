// LCD_BacklightRGB.h
#ifndef LCD_BACKLIGHTRGB_H
#define LCD_BACKLIGHTRGB_H

#include <Arduino.h>
#include "BacklightColors.h"
#include "BacklightRGB.h"
#include "BacklightCW.h"

class LCD_BacklightRGB {
private:
  BacklightRGB rgb;
  BacklightCW cw;

public:
  LCD_BacklightRGB(int r, int g, int b);
  void begin();
  void setBrightness(int brightness);
  void setRGB(int red, int green, int blue);
  void setRGB(int red, int green, int blue, int brightness);
  void setRGB(uint32_t hexColor);
  void setRGB(uint32_t hexColor, int brightness);
  void off();
  void setWhite();
  void setWhite(int brightness);
  void setPink();
  void setPink(int brightness);
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
};

#endif
