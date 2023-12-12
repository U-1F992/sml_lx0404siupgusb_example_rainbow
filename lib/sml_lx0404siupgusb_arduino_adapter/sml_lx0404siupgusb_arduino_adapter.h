#ifndef SML_LX0404SIUPGUSB_ARDUINO_ADAPTER_H_
#define SML_LX0404SIUPGUSB_ARDUINO_ADAPTER_H_

#include <Arduino.h>
#include "sml_lx0404siupgusb.h"

typedef struct SML_LX0404SIUPGUSBArduinoAdapter
{
    SML_LX0404SIUPGUSBAnalogOutputInterface parent;
    pin_size_t pin;
    int max_value;
} SML_LX0404SIUPGUSBArduinoAdapter;

SML_LX0404SIUPGUSBArduinoAdapter *sml_lx0404siupgusb_arduino_adapter_new(const pin_size_t pin, const int resolution);
void sml_lx0404siupgusb_arduino_adapter_delete(SML_LX0404SIUPGUSBArduinoAdapter *self);

#endif
