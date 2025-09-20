#include "fdf.h"

/*extract respective 8-bit values for RGB into t_colour struct*/
void get_rgb(uint32_t c, t_colour *colour) // redundant
{
	colour->rr = (c >> 16) & 0xFF;
	colour->gg = (c >> 8) & 0xFF;
	colour->bb = c & 0xFF;
}

/*extract respective 8-bit values for RGB into t_colour struct*/
void set_rgb(uint32_t c, t_node *node)
{
	node->rr = (c >> 16) & 0xFF;
	node->gg = (c >> 8) & 0xFF;
	node->bb = c & 0xFF;
}

/*combine 8-bit RGB values into 32 bit colour value*/
uint32_t	blend_rgb_node(t_node *node)
{
	uint32_t	result;

	result = 0;
	result |= node->rr;
	result = result << 8;
	result |= node->gg;
	result = result << 8;
	result |= node->bb;
	result = result << 8;
	return result | 0xFF;
}

uint32_t	blend_rgb(uint8_t rr, uint8_t gg, uint8_t bb, uint8_t aa)
{
	uint32_t	result;

	result = 0;
	result |= rr;
	result = result << 8;
	result |= gg;
	result = result << 8;
	result |= bb;
	result = result << 8;
	return result | 0xFF;
}


uint8_t clampf_u8(float value) // move to math
{
	if (value < 0)
		return (0);
	else if (value > 255)
		return (255);
	else
		return ((uint8_t)(value + 0.5));
}

/*blend two 32-bit colours together according to a weight value (0.0 - 1.0)*/
uint32_t blend_colour(t_node node_0, t_node node_1, float weight)
{
	uint8_t rr;
	uint8_t gg;
	uint8_t bb;
	
	rr = clampf_u8((weight * node_1.rr) + ((1 - weight) * node_0.rr));
	gg = clampf_u8((weight * node_1.gg) + ((1 - weight) * node_0.gg));
	bb = clampf_u8((weight * node_1.bb) + ((1 - weight) * node_0.bb));
	return (blend_rgb(rr, gg, bb, 255));
}


uint32_t get_colour(t_node p0, t_node p1, float weight)
{
	uint32_t colour;

	colour = blend_colour(p0, p1, weight);

	//return (0xFF09FFFD);
	
	return (colour);
}

/*using floats*/
float get_weight(t_node start, t_point current, t_node end) //less expensive method? -> pass line object?
{
	float d0;
	float d1;
	float weight;

	d0 = sqrt(pow((current.pix_x - start.pix_x), 2) + pow((current.pix_y - start.pix_y), 2));
	d1 = sqrt(pow((end.pix_x - current.pix_x), 2) + pow((end.pix_y - current.pix_y), 2));

	weight = (d0 / (d0 + d1));
	return (weight);
}
/*
length_2	- length of line squared
wx/wy		- current displacement
weight		- dot product / len squared -> unwraps everything -> no sqrt
*/
float get_weight_2(t_line line)
{
    float length_2;
	float wx;
	float wy;
	float weight;
	
	length_2 = line.dx * line.dx + line.dy * line.dy;

    wx = line.pix_x - line.start_x;
    wy = line.pix_y - line.start_y;


    weight = (wx*line.dx + wy*line.dy) / length_2;
    if (weight < 0) weight = 0;
    if (weight > 1) weight = 1;
    return (weight);
}
