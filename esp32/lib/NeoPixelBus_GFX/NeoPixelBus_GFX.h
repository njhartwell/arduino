#ifndef _NEOPIXELBUS_GFX
#define _NEOPIXELBUS_GFX

#include <Adafruit_GFX.h>
#include <NeoPixelBus.h>

template<typename T_COLOR_FEATURE, typename T_METHOD, typename T_LAYOUT> class NeoPixelBus_GFX: Adafruit_GFX {
    NeoPixelBus<T_COLOR_FEATURE, T_METHOD> strip;
    NeoTopology<T_LAYOUT> topo;

    public :
        NeoPixelBus_GFX(NeoPixelBus<T_COLOR_FEATURE, T_METHOD> strip, NeoTopology<T_LAYOUT> topo, int16_t w, int16_t h) {}
        void drawPixel(int16_t x, int16_t y, uint16_t color) {
            strip.SetPixelColor(topo.Map(x, y), RgbColor(100, 0, 0));
        }
}

#endif // _NEOPIXELBUS_GFX
