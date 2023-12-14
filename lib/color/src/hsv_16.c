#include "color.h"

extern inline ColorHSV16 *color_hsv_16_new(const uint16_t hue, const uint16_t saturation, const uint16_t value);
extern inline void color_hsv_16_delete(ColorHSV16 *self);

ColorRGB16 *color_hsv_16_to_rgb_16(ColorHSV16 *self)
{
    if (self->saturation == 0)
    {
        return color_rgb_16_new(self->value, self->value, self->value);
    }

    uint8_t region = ((uint32_t)self->hue * 6) / ((uint32_t)UINT16_MAX + 1);
    // assert(0 <= region && region <= 5);
    uint16_t remainder = ((uint32_t)self->hue * 6) % ((uint32_t)UINT16_MAX + 1);

    uint16_t p = ((uint32_t)self->value * (UINT16_MAX - self->saturation)) / UINT16_MAX;
    uint16_t q = ((uint32_t)self->value * (UINT16_MAX - (((uint32_t)self->saturation * remainder) / ((uint32_t)UINT16_MAX + 1)))) / UINT16_MAX;
    uint16_t t = ((uint32_t)self->value * (UINT16_MAX - (((uint32_t)self->saturation * (UINT16_MAX - remainder)) / ((uint32_t)UINT16_MAX + 1)))) / UINT16_MAX;

    switch (region)
    {
    case 0:
        return color_rgb_16_new(self->value, t, p);
    case 1:
        return color_rgb_16_new(q, self->value, p);
    case 2:
        return color_rgb_16_new(p, self->value, t);
    case 3:
        return color_rgb_16_new(p, q, self->value);
    case 4:
        return color_rgb_16_new(t, p, self->value);
    case 5:
    default:
        return color_rgb_16_new(self->value, p, q);
    }
}
