#ifndef COLOR_H_
#define COLOR_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdlib.h>

typedef struct ColorRGB16
{
    uint16_t red;
    uint16_t green;
    uint16_t blue;
} ColorRGB16;

inline ColorRGB16 *color_rgb_16_new(const uint16_t red, const uint16_t green, const uint16_t blue)
{
    ColorRGB16 *self = (ColorRGB16 *)malloc(sizeof(ColorRGB16));
    if (self == NULL)
    {
        return NULL;
    }

    self->red = red;
    self->green = green;
    self->blue = blue;

    return self;
}

inline void color_rgb_16_delete(ColorRGB16 *self)
{
    free(self);
}

typedef struct ColorHSV16
{
    /**
     * [0, 360) deg mapped to [0, UINT16_MAX].
     * hue=UINT16_MAX does not imply hue=0, but means the closest representable value to 360deg.
     */
    uint16_t hue;
    /**
     * [0, 1] mapped to [0, UINT16_MAX].
     */
    uint16_t saturation;
    /**
     * [0, 1] mapped to [0, UINT16_MAX].
     */
    uint16_t value;
} ColorHSV16;

inline ColorHSV16 *color_hsv_16_new(const uint16_t hue, const uint16_t saturation, const uint16_t value)
{
    ColorHSV16 *self = (ColorHSV16 *)malloc(sizeof(ColorHSV16));
    if (self == NULL)
    {
        return NULL;
    }

    self->hue = hue;
    self->saturation = saturation;
    self->value = value;

    return self;
}

inline void color_hsv_16_delete(ColorHSV16 *self)
{
    free(self);
}

ColorRGB16 *color_hsv_16_to_rgb_16(ColorHSV16 *self);

#ifdef __cplusplus
}
#endif

#endif
