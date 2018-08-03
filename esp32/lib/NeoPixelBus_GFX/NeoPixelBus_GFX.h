#ifndef _NEOPIXELBUS_GFX
#define _NEOPIXELBUS_GFX

#include <Adafruit_GFX.h>
#include <NeoPixelBus.h>
#include <Arduino.h>

template<typename T_COLOR_FEATURE, typename T_METHOD, typename T_LAYOUT> class NeoPixelBus_GFX: public Adafruit_GFX {
    NeoPixelBus<T_COLOR_FEATURE, T_METHOD>* strip;
    NeoTopology<T_LAYOUT>* topo;

    public :
        NeoPixelBus_GFX(NeoPixelBus<T_COLOR_FEATURE, T_METHOD>* s, NeoTopology<T_LAYOUT>* t, int16_t w, int16_t h): Adafruit_GFX(w, h) {
            this->strip = s;
            this->topo = t;
        }
        void drawPixel(int16_t x, int16_t y, uint16_t color) {
            if (color == 0) {
                strip->SetPixelColor(topo->Map(x, y), RgbColor(0, 0, 0));
            } else {
                strip->SetPixelColor(topo->Map(x, y), RgbColor(50, 0, 0));
            }
        }

        void fillScreen(uint16_t color) {
            strip->ClearTo(RgbColor(0));
        }
};

#endif // _NEOPIXELBUS_GFX
