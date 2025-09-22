/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:48:39 by crabin            #+#    #+#             */
/*   Updated: 2025/09/21 17:49:49 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Extract respective 8-bit values for RGB into t_colour struct*/
void	set_rgb(uint32_t c, t_node *node)
{
	node->rr = (c >> 16) & 0xFF;
	node->gg = (c >> 8) & 0xFF;
	node->bb = c & 0xFF;
}

/*Blend components and return 0xRRGGBBAA*/
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
	return result | aa;
}

/*
Blend two colours according to a weight factor
*/
uint32_t	get_colour(t_node p0, t_node p1, float weight)
{
	uint8_t	rr;
	uint8_t	gg;
	uint8_t	bb;
	
	rr = clampf_u8((weight * p1.rr) + ((1 - weight) * p0.rr));
	gg = clampf_u8((weight * p1.gg) + ((1 - weight) * p0.gg));
	bb = clampf_u8((weight * p1.bb) + ((1 - weight) * p0.bb));
	return (blend_rgb(rr, gg, bb, 255));
}

/*
Return a weight between 0-1 indicating how far along line current pix x/y are
length_2	- length of line squared
wx/wy		- current displacement
weight		- dot product / len squared -> unwraps everything -> no sqrt
*/
float	get_weight_2(t_line line)
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
