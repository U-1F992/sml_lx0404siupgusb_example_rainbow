#ifndef SML_LX0404SIUPGUSB_H_
#define SML_LX0404SIUPGUSB_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct SML_LX0404SIUPGUSBAnalogOutputInterface
{
    void (*write)(struct SML_LX0404SIUPGUSBAnalogOutputInterface *self, const uint16_t value);
} SML_LX0404SIUPGUSBAnalogOutputInterface;

typedef struct SML_LX0404SIUPGUSB
{
    SML_LX0404SIUPGUSBAnalogOutputInterface *red;
    SML_LX0404SIUPGUSBAnalogOutputInterface *green;
    SML_LX0404SIUPGUSBAnalogOutputInterface *blue;
} SML_LX0404SIUPGUSB;

typedef enum SML_LX0404SIUPGUSBColorState
{
    SML_LX0404SIUPGUSB_ON = UINT16_MAX,
    SML_LX0404SIUPGUSB_OFF = 0
} SML_LX0404SIUPGUSBState;

void sml_lx0404siupgusb_set(SML_LX0404SIUPGUSB *self, const uint16_t red, const uint16_t green, const uint16_t blue);
void sml_lx0404siupgusb_off(SML_LX0404SIUPGUSB *self);
SML_LX0404SIUPGUSB *sml_lx0404siupgusb_new(SML_LX0404SIUPGUSBAnalogOutputInterface *red, SML_LX0404SIUPGUSBAnalogOutputInterface *green, SML_LX0404SIUPGUSBAnalogOutputInterface *blue);
void sml_lx0404siupgusb_delete(SML_LX0404SIUPGUSB *self);

#ifdef __cplusplus
}
#endif

#endif