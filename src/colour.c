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

/*blend two 32-bit colours together according to a weight value (0.0 - 1.0)*/
uint32_t blend_colour(uint32_t p0, uint32_t p1, float weight)
{
	t_colour c0;
	t_colour c1;
	t_colour result;

	if (p0 == 0)
		p0 = UINT32_MAX;
	if (p1 == 0)
		p1 = UINT32_MAX;
	get_rgb(p0, &c0);
	get_rgb(p1, &c1);

	result.rr = (uint8_t)(weight * c1.rr) + (uint8_t)((1 - weight) * c0.rr);
	result.gg = (uint8_t)(weight * c1.gg) + (uint8_t)((1 - weight) * c0.gg);
	result.bb = (uint8_t)(weight * c1.bb) + (uint8_t)((1 - weight) * c0.bb);
	return (blend_rgb(&result));
}

// /*using floats*/
// float get_weight(t_point p0, t_point p1, t_point start)
// {
// 	float d0;
// 	float d1;
// 	float weight;

// 	d0 = sqrt(pow((p0.pix_x - start.pix_x), 2) + pow((p0.pix_y - start.pix_y), 2));
// 	d1 = sqrt(pow((p1.pix_x - p0.pix_x), 2) + pow((p1.pix_y - p0.pix_y), 2));

// 	weight = (d0 / (d0 + d1));
// 	return (weight);
// }

float weight_scuffed(t_point start, t_point p0, t_line line)
{
	float p_x;
	float p_y;

	p_x = ft_abs(((float)p0.pix_x - (float)start.pix_x)) / (float)line.dx;
	p_y = ft_abs(((float)p0.pix_y - (float)start.pix_y)) / (float)line.dy;

	if (p_x == 0)
		return (p_y);
	else if (p_y == 0)
		return (p_x);
	else
		return ((p_x + p_y) / 2);
}

/*less float ops*/
// float get_weight(t_point p, t_point p0, t_point p1)
// {
// 	float dx;
// 	float dy;
// 	float num;
// 	float den;

// 	dx = p1.pix_x - p0.pix_x;
// 	dy = p1.pix_y - p0.pix_y;
// 	num = ((p.pix_x - p0.pix_x) * dx + (p.pix_y - p0.pix_y) * dy);
// 	den =  dx * dx + dy * dy;
// 	return (num / den);
// }

uint32_t get_colour(t_point p0, t_point p1, float weight)
{
	uint32_t colour;

	// p0.colour = 0x80FFFF;
	// p1.colour = 0xFF00FF;

	//colour = blend_colour(p0.colour, p1.colour, weight);
	colour = blend_colour(p0.colour, p1.colour, 0.5);
	
	// return (0x80FFFFFF);
	return (colour);
}