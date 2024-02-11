#include "matrix.h"

LedMatrix::LedMatrix() {
    FastLED.addLeds<MATRIX_LED_TYPE, MATRIX_PIN, GRB>(leds, N_LEDS).setCorrection(TypicalLEDStrip);
}

void LedMatrix::setColor(byte height, byte width, CRGB color) {
    byte index = calculateIndex(height, width);
    this->setColor(index, color);
}

void LedMatrix::setColor(byte index, CRGB color) {
    this->leds[index] = color;
}

void LedMatrix::redraw() {
    /// It's necessary to call .show() twice
    FastLED.show();
    FastLED.show();
}

void LedMatrix::clear() {
    fill_solid(leds, N_LEDS, CRGB(0, 0, 0));
}

byte LedMatrix::calculateIndex(byte height, byte width) {
    byte startRowIdx = N_COL * height;
    byte isEven = height % 2;
    return isEven * (startRowIdx + (N_COL - width - 1)) + (1 - isEven) * (startRowIdx + width);;
}
