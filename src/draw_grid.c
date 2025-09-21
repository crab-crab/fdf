/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:40 by crabin            #+#    #+#             */
/*   Updated: 2025/09/21 17:44:36 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*draw a line between two horizontally adjacent nodes in map grid*/
void	connect_h(t_display	*display, uint32_t x, uint32_t y)
{
	display->p1 = &display->map->nodes[get_index(x + 1, y, display->map)];
	if (valid_point(*display->p0) || valid_point(*display->p1))
		draw_line(*display->p0, *display->p1, display->g_img);
}

/*draw a line between two vertically adjacent nodes in map grid*/
void	connect_v(t_display	*display, uint32_t x, uint32_t y)
{
	display->p1 = &display->map->nodes[get_index(x, y + 1, display->map)];
	if (valid_point(*display->p0) || valid_point(*display->p1))
		draw_line(*display->p0, *display->p1, display->g_img);
}

/*
iterate over grid and update each node
precalc sin/cos of rotation values to save on compute
*/
void	update_grid(t_display	*display)
{
	int		index;
	int		size;
	t_map	*map;

	map = display->map;
	size = (display->map->size_x * display->map->size_y);
	index = 0;
	display->cos_rx = cos(display->rx);
	display->sin_rx = sin(display->rx);
	display->cos_ry = cos(display->ry);
	display->sin_ry = sin(display->ry);
	display->cos_rz = cos(display->rz);
	display->sin_rz = sin(display->rz);
	while (index < size)
	{
		resolve_node(display, &map->nodes[index]);
		index++;
	}
}

/*
iterate over grid and if not last in row/col, draw relevant line
*/
void	draw_grid(t_display	*dsp)
{
	int32_t	x;
	int32_t	y;

	update_grid(dsp);
	y = 0;
	while (y < dsp->map->size_y)
	{
		x = 0;
		while (x < dsp->map->size_x)
		{
			dsp->p0 = &dsp->map->nodes[get_index(x, y, dsp->map)];
			if (x < dsp->map->size_x - 1)
				connect_h(dsp, x, y);
			if (y < dsp->map->size_y - 1)
				connect_v(dsp, x, y);
			if (dsp->node > 0)
				draw_circle(dsp->g_img, *dsp->p0, dsp->node_rad, dsp->node_f);
			x++;
		}
		y++;
	}
}
