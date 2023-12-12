#include "color.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

void rgb_color_delete(RGBColor *rgb)
{
    if (rgb == NULL)
    {
        return;
    }

    free(rgb);
}

HSVColor *hsv_color_new(const double hue, const double saturation, const double value)
{
    if (saturation < 0.0 || 1.0 < saturation || value < 0.0 || 1.0 < value)
    {
        return NULL;
    }

    HSVColor *hsv = (HSVColor *)malloc(sizeof(HSVColor));
    if (hsv == NULL)
    {
        return NULL;
    }

    // Normalize the hue value
    hsv->hue = fmod(hue, 360.0);
    if (hsv->hue < 0.0)
    {
        hsv->hue += 360.0;
    }
    hsv->saturation = saturation;
    hsv->value = value;

    return hsv;
}

void hsv_color_delete(HSVColor *hsv)
{
    if (hsv == NULL)
    {
        return;
    }

    free(hsv);
}

RGBColor *hsv_color_to_rgb(HSVColor *hsv)
{
    if (hsv == NULL)
    {
        return NULL;
    }

    RGBColor *rgb = (RGBColor *)malloc(sizeof(RGBColor));
    if (rgb == NULL)
    {
        return NULL;
    }
    double r, g, b;

    int hue_sector = (int)(hsv->hue / 60.0);
    double hue_fractional_part = (hsv->hue / 60.0) - hue_sector;
    double temp_1 = hsv->value * (1.0 - hsv->saturation);
    double temp_2 = hsv->value * (1.0 - hsv->saturation * hue_fractional_part);
    double temp_3 = hsv->value * (1.0 - hsv->saturation * (1.0 - hue_fractional_part));

    switch (hue_sector)
    {
    case 0:
        r = hsv->value;
        g = temp_3;
        b = temp_1;
        break;
    case 1:
        r = temp_2;
        g = hsv->value;
        b = temp_1;
        break;
    case 2:
        r = temp_1;
        g = hsv->value;
        b = temp_3;
        break;
    case 3:
        r = temp_1;
        g = temp_2;
        b = hsv->value;
        break;
    case 4:
        r = temp_3;
        g = temp_1;
        b = hsv->value;
        break;
    default:
        r = hsv->value;
        g = temp_1;
        b = temp_2;
        break;
    }

    rgb->red = (uint8_t)(r * 255);
    rgb->green = (uint8_t)(g * 255);
    rgb->blue = (uint8_t)(b * 255);

    return rgb;
}
