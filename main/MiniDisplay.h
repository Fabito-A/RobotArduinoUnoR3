// =================================================================
// CLASE: MiniDisplay
// Responsabilidad: muestra en pantalla usando el chip OLED I2C SSD1306.
// =================================================================
#ifndef MINIDISPLAY_H
#define MINIDISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

class MiniDisplay {
    private:
    static const int SCREEN_WIDTH = 128;
    static const int SCREEN_HEIGHT = 64;
    static const int OLED_RESET = -1;
    Adafruit_SSD1306 display;

  public:
    MiniDisplay();
    bool begin();
    void showText(const String &text, int x = 0, int y = 0, int textSize = 2);
    void clear();
    void showCheckIcon(int x = 80, int y = 16);
    void showWarningIcon(int x = 80, int y = 16);

};

#endif