// =================================================================
// CLASE: implementacion de la clase MiniDisplay
// Responsabilidad: Muestra en pantalla usando el chip OLED I2C SSD1306.
// =================================================================
#include "MiniDisplay.h"

MiniDisplay::MiniDisplay()
  : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{}

bool MiniDisplay::begin() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    return false;
  }
  display.clearDisplay();
  display.display();
  return true;
}

void MiniDisplay::showText(const String &text, int x, int y, int textSize) {
  display.clearDisplay();
  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.println(text);
  display.display();
}

void MiniDisplay::clear() {
  display.clearDisplay();
  display.display();
}

// ICONO DE "CHECK"
void MiniDisplay::showCheckIcon(int x, int y) {
  // Círculo de fondo
  display.drawCircle(x+16, y+16, 15, SSD1306_WHITE);
  // Palomita
  display.drawLine(x+8,  y+16, x+14, y+22, SSD1306_WHITE);
  display.drawLine(x+14, y+22, x+24, y+10, SSD1306_WHITE);
  display.display();
}

// ICONO DE "WARNING"
void MiniDisplay::showWarningIcon(int x, int y) {
  // Triángulo de advertencia
  display.drawTriangle(x+16, y+2, x+2, y+28, x+30, y+28, SSD1306_WHITE);
  // Signo de exclamación
  display.drawLine(x+16, y+8, x+16, y+20, SSD1306_WHITE); // Línea
  display.fillRect(x+15, y+22, 3, 3, SSD1306_WHITE);     // Punto
  display.display();
}