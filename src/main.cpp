#include <Arduino.h>

#include "color.h"
#include "sml_lx0404siupgusb.h"
#include "sml_lx0404siupgusb_arduino_adapter.h"

static const int ANALOG_WRITE_RESOLUTION = 16;

static const pin_size_t PIN_RED = 23;
static const pin_size_t PIN_GREEN = 24;
static const pin_size_t PIN_BLUE = 25;

static SML_LX0404SIUPGUSBNullDigitalOutput *anode;
static SML_LX0404SIUPGUSBArduinoAnalogAdapter *pwm_red;
static SML_LX0404SIUPGUSBArduinoAnalogAdapter *pwm_green;
static SML_LX0404SIUPGUSBArduinoAnalogAdapter *pwm_blue;
static SML_LX0404SIUPGUSB *led;

static ColorRGB16 *rainbow_colors[3600];

static void precalculate_rainbow_colors()
{
    for (int hue = 0; hue < 3600; hue++)
    {
        ColorHSV16 *hsv = color_hsv_16_new(((double)hue / 3600) * UINT16_MAX, UINT16_MAX, UINT16_MAX);
        assert(hsv != NULL);

        ColorRGB16 *rgb = color_hsv_16_to_rgb_16(hsv);
        assert(rgb != NULL);
        color_hsv_16_delete(hsv);
        hsv = NULL;

        rainbow_colors[hue] = rgb;
    }
}

static void rainbow()
{
    for (size_t i = 0; i < 3600; i++)
    {
        sml_lx0404siupgusb_set(led, rainbow_colors[i]->red, rainbow_colors[i]->green, rainbow_colors[i]->blue);
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
    anode = sml_lx0404siupgusb_null_digital_output_new();
    assert(anode != NULL);

    pinMode(PIN_RED, OUTPUT);
    digitalWrite(PIN_RED, HIGH);
    pwm_red = sml_lx0404siupgusb_arduino_analog_adapter_new(PIN_RED, ANALOG_WRITE_RESOLUTION);
    assert(pwm_red != NULL);

    pinMode(PIN_GREEN, OUTPUT);
    digitalWrite(PIN_GREEN, HIGH);
    pwm_green = sml_lx0404siupgusb_arduino_analog_adapter_new(PIN_GREEN, ANALOG_WRITE_RESOLUTION);
    assert(pwm_green != NULL);

    pinMode(PIN_BLUE, OUTPUT);
    digitalWrite(PIN_BLUE, HIGH);
    pwm_blue = sml_lx0404siupgusb_arduino_analog_adapter_new(PIN_BLUE, ANALOG_WRITE_RESOLUTION);
    assert(pwm_blue != NULL);

    led = sml_lx0404siupgusb_new((SML_LX0404SIUPGUSBDigitalOutputInterface *)anode,
                                 (SML_LX0404SIUPGUSBAnalogOutputInterface *)pwm_red,
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
    sml_lx0404siupgusb_on(led);
    rainbow();
    delay(250);

    blink_red_twice();
    delay(250);

    blink_green_twice();
    delay(250);

    blink_blue_twice();
    delay(250);
}