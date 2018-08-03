// NeoPixelTest
// This example will cycle between showing four pixels as Red, Green, Blue, White
// and then showing those pixels as Black.
//
// Included but commented out are examples of configuring a NeoPixelBus for
// different color order including an extra white channel, different data speeds, and
// for Esp8266 different methods to send the data.
// NOTE: You will need to make sure to pick the one for your platform
//
//
// There is serial output of the current state so you can confirm and follow along
//

#include <NeoPixelBus.h>
#include <NeoPixelBus_GFX.h>

extern void initWiFiAndNTP();
extern String getTime();

const uint8_t PanelWidth = 32;
const uint8_t PanelHeight = 8;
const uint16_t PixelCount = 256; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 19;  // make sure to set this to the correct pin, ignored for Esp8266
const uint16_t left = 0;
const uint16_t right = PanelWidth - 1;
const uint16_t top = 0;
const uint16_t bottom = PanelHeight - 1;

#define colorSaturation 128

// three element pixels, in different order and speeds
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);
NeoTopology<ColumnMajorAlternatingLayout> topo(PanelWidth, PanelHeight);
NeoPixelBus_GFX<NeoGrbFeature, Neo800KbpsMethod, ColumnMajorAlternatingLayout> matrix (&strip, &topo, PanelWidth, PanelHeight);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslWhite(white);
HslColor hslBlack(black);

String sTime = "12:00";

void setup()
{
    //Serial.begin(115200);
    //while (!Serial); // wait for serial attach

    initWiFiAndNTP();

    Serial.println();
    Serial.println("Initializing...");
    Serial.flush();

    // this resets all the neopixels to an off state
    strip.Begin();
    //matrix.print("Hello");
    strip.Show();

    Serial.println();
    Serial.println("Running...");
}

bool showed = false;

void loop()
{
    matrix.setCursor(0, 0);
    matrix.fillScreen(0);
    matrix.print(getTime());
    strip.Show();
    delay(1000);
}
