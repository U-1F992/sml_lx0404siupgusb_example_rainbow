#ifndef COLOR_H_
#define COLOR_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdlib.h>

typedef struct RGBColor
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} RGBColor;

void rgb_color_delete(RGBColor *rgb);

typedef struct HSVColor
{
    double hue;
    double saturation;
    double value;
} HSVColor;

HSVColor *hsv_color_new(const double hue, const double saturation, const double value);
void hsv_color_delete(HSVColor *hsv);
RGBColor *hsv_color_to_rgb(HSVColor *hsv);

#ifdef __cplusplus
}
#endif

#endif
