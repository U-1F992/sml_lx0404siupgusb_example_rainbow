#ifndef SML_LX0404SIUPGUSB_H_
#define SML_LX0404SIUPGUSB_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdlib.h>

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

inline void sml_lx0404siupgusb_set(SML_LX0404SIUPGUSB *self, const uint16_t red, const uint16_t green, const uint16_t blue)
{
    if (self == NULL)
    {
        return;
    }

    self->red->write(self->red, UINT16_MAX - red);
    self->green->write(self->green, UINT16_MAX - green);
    self->blue->write(self->blue, UINT16_MAX - blue);
}

inline void sml_lx0404siupgusb_off(SML_LX0404SIUPGUSB *self)
{
    sml_lx0404siupgusb_set(self, SML_LX0404SIUPGUSB_OFF, SML_LX0404SIUPGUSB_OFF, SML_LX0404SIUPGUSB_OFF);
}

inline SML_LX0404SIUPGUSB *sml_lx0404siupgusb_new(SML_LX0404SIUPGUSBAnalogOutputInterface *red, SML_LX0404SIUPGUSBAnalogOutputInterface *green, SML_LX0404SIUPGUSBAnalogOutputInterface *blue)
{
    if (red == NULL || green == NULL || blue == NULL)
    {
        return NULL;
    }

    SML_LX0404SIUPGUSB *self = (SML_LX0404SIUPGUSB *)malloc(sizeof(SML_LX0404SIUPGUSB));
    if (self == NULL)
    {
        return NULL;
    }

    self->red = red;
    self->green = green;
    self->blue = blue;

    sml_lx0404siupgusb_off(self);

    return self;
}

inline void sml_lx0404siupgusb_delete(SML_LX0404SIUPGUSB *self)
{
    if (self == NULL)
    {
        return;
    }

    sml_lx0404siupgusb_off(self);

    free(self);
}

#ifdef __cplusplus
}
#endif

#endif