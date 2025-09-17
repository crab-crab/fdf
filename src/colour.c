#include "fdf.h"

/*extract respective 8-bit values for RGB into t_colour struct*/
void get_rgb(uint32_t c, t_colour *colour)
{
	colour->rr = (c >> 16) & 0xFF;
	colour->gg = (c >> 8) & 0xFF;
	colour->bb = c & 0xFF;
}

/*combine 8-bit RGB values into 32 bit colour value*/
uint32_t	blend_rgb(t_colour *colour)
{
	uint32_t	result;

	result = 0;
	result |= colour->rr;
	result = result << 8;
	result |= colour->gg;
	result = result << 8;
	result |= colour->bb;
	result = result << 8;
	return result | 0xFF;
}


uint8_t clampf_u8(float value)
{
	if (value < 0)
		return (0);
	else if (value > 255)
		return (255);
	else
		return ((uint8_t)(value + 0.5));
}

/*blend two 32-bit colours together according to a weight value (0.0 - 1.0)*/
uint32_t blend_colour(uint32_t p0, uint32_t p1, float weight)
{
	t_colour c0;
	t_colour c1;
	t_colour result;

	get_rgb(p0, &c0);
	get_rgb(p1, &c1);

	result.rr = clampf_u8((weight * c1.rr) + ((1 - weight) * c0.rr));
	result.gg = clampf_u8((weight * c1.gg) + ((1 - weight) * c0.gg));
	result.bb = clampf_u8((weight * c1.bb) + ((1 - weight) * c0.bb));
	uint32_t colour = blend_rgb(&result);
	//printf("colour: %d\n", colour);
	return (colour);
}


uint32_t get_colour(t_point p0, t_point p1, float weight)
{
	uint32_t colour;

	colour = blend_colour(p0.colour, p1.colour, weight);
	//return (0xFF09FFFD);
	
	return (colour);
}

/*using floats*/
float get_weight(t_point p0, t_point start, t_point p1)
{
	float d0;
	float d1;
	float weight;

	d0 = sqrt(pow((p0.pix_x - start.pix_x), 2) + pow((p0.pix_y - start.pix_y), 2));
	d1 = sqrt(pow((p1.pix_x - p0.pix_x), 2) + pow((p1.pix_y - p0.pix_y), 2));

	weight = (d0 / (d0 + d1));
	return (weight);
}
