#include <Arduino.h>

#include "color.h"
#include "sml_lx0404siupgusb.h"
#include "sml_lx0404siupgusb_arduino_adapter.h"

static const int ANALOG_WRITE_RESOLUTION = 16;

static const pin_size_t PIN_RED = 23;
static const pin_size_t PIN_GREEN = 24;
static const pin_size_t PIN_BLUE = 25;

static SML_LX0404SIUPGUSBArduinoAdapter *pwm_red;
static SML_LX0404SIUPGUSBArduinoAdapter *pwm_green;
static SML_LX0404SIUPGUSBArduinoAdapter *pwm_blue;
static SML_LX0404SIUPGUSB *led;

typedef struct RGB16Color
{
    uint16_t red;
    uint16_t green;
    uint16_t blue;
} RGB16Color;

static RGB16Color *rainbow_colors[3600];

static void precalculate_rainbow_colors()
{
    for (int hue = 0; hue < 3600; hue++)
    {
        HSVColor *hsv = hsv_color_new((double)hue / 10, 1.0, 1.0);
        assert(hsv != NULL);

        RGBColor *rgb = hsv_color_to_rgb(hsv);
        assert(rgb != NULL);

        RGB16Color *rgb16 = (RGB16Color *)malloc(sizeof(RGB16Color));
        assert(rgb16 != NULL);
        rgb16->red = (uint16_t)(((double)rgb->red / UINT8_MAX) * UINT16_MAX);
        rgb16->green = (uint16_t)(((double)rgb->green / UINT8_MAX) * UINT16_MAX);
        rgb16->blue = (uint16_t)(((double)rgb->blue / UINT8_MAX) * UINT16_MAX);

        rainbow_colors[hue] = rgb16;

        rgb_color_delete(rgb);
        rgb = NULL;
        hsv_color_delete(hsv);
        hsv = NULL;
    }
}

static void rainbow()
{
    for (size_t i = 0; i < 3600; i++)
    {
        RGB16Color *rgb = rainbow_colors[i];
        sml_lx0404siupgusb_set(led, rgb->red, rgb->green, rgb->blue);
        delay(1);
    }
    sml_lx0404siupgusb_off(led);
}

static void blink_red_twice()
{
    for (int _ = 0; _ < 2; _++)
    {
        sml_lx0404siupgusb_set(led, SML_LX0404SIUPGUSB_ON, SML_LX0404SIUPGUSB_OFF, SML_LX0404SIUPGUSB_OFF);
        delay(100);
        sml_lx0404siupgusb_off(led);
        delay(100);
    }
}

static void blink_green_twice()
{
    for (int _ = 0; _ < 2; _++)
    {
        sml_lx0404siupgusb_set(led, SML_LX0404SIUPGUSB_OFF, SML_LX0404SIUPGUSB_ON, SML_LX0404SIUPGUSB_OFF);
        delay(100);
        sml_lx0404siupgusb_off(led);
        delay(100);
    }
}

static void blink_blue_twice()
{
    for (int _ = 0; _ < 2; _++)
    {
        sml_lx0404siupgusb_set(led, SML_LX0404SIUPGUSB_OFF, SML_LX0404SIUPGUSB_OFF, SML_LX0404SIUPGUSB_ON);
        delay(100);
        sml_lx0404siupgusb_off(led);
        delay(100);
    }
}

void setup_sml_lx0404siupgusb()
{
    pinMode(PIN_RED, OUTPUT);
    digitalWrite(PIN_RED, HIGH);
    pwm_red = sml_lx0404siupgusb_arduino_adapter_new(PIN_RED, ANALOG_WRITE_RESOLUTION);
    assert(pwm_red != NULL);

    pinMode(PIN_GREEN, OUTPUT);
    digitalWrite(PIN_GREEN, HIGH);
    pwm_green = sml_lx0404siupgusb_arduino_adapter_new(PIN_GREEN, ANALOG_WRITE_RESOLUTION);
    assert(pwm_green != NULL);

    pinMode(PIN_BLUE, OUTPUT);
    digitalWrite(PIN_BLUE, HIGH);
    pwm_blue = sml_lx0404siupgusb_arduino_adapter_new(PIN_BLUE, ANALOG_WRITE_RESOLUTION);
    assert(pwm_blue != NULL);

    led = sml_lx0404siupgusb_new((SML_LX0404SIUPGUSBAnalogOutputInterface *)pwm_red,
                                 (SML_LX0404SIUPGUSBAnalogOutputInterface *)pwm_green,
                                 (SML_LX0404SIUPGUSBAnalogOutputInterface *)pwm_blue);
    assert(led != NULL);
}

void setup()
{
    analogWriteResolution(ANALOG_WRITE_RESOLUTION);

    setup_sml_lx0404siupgusb();

    precalculate_rainbow_colors();
}

void loop()
{
    rainbow();
    delay(250);

    blink_red_twice();
    delay(250);

    blink_green_twice();
    delay(250);

    blink_blue_twice();
    delay(250);
}