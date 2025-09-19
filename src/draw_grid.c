/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:40 by crabin            #+#    #+#             */
/*   Updated: 2025/09/18 21:11:35 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*draw a line between two horizontally adjacent nodes in map grid*/
void connect_h(t_display	*display, uint32_t x, uint32_t y)
{
	//display->p0 = &display->map->nodes[get_index(x, y, display->map)];
	display->p1 = &display->map->nodes[get_index(x + 1, y, display->map)];
	draw_update(display);
}

/*draw a line between two vertically adjacent nodes in map grid*/
void connect_v(t_display	*display, uint32_t x, uint32_t y)
{
	//display->p0 = &display->map->nodes[get_index(x, y, display->map)];
	display->p1 = &display->map->nodes[get_index(x, y + 1, display->map)];
	draw_update(display);
}


void update_grid(t_display	*display)
{
	int		index;
	int		size;
	t_map	map;

	map = display->map;
	size = (display->map->size_x * display->map->size_y);

	index = 0;
	display->cos_rx = cos(rx);
	display->sin_rx = sin(rx);
	display->cos_ry = cos(ry);
	display->sin_ry = sin(ry);
	display->cos_rz = cos(rz);
	display->sin_rz = sin(rz);
	while (index < size)
	{
		resolve_node(display, &map->nodes[index]);
		index++;
	}
}

/*
Add
	-Node drawing
	-Vertex->helper function
*/
void draw_grid(t_display	*display)
{
	uint32_t x;
	uint32_t y;

	update_grid(display);
	y = 0;
	while (y < display->map->size_y)
	{
		x = 0;
		while (x < display->map->size_x)
		{
			display->p0 = &display->map->nodes[get_index(x, y, display->map)];
			if (x < display->map->size_x - 1)
				connect_h(display, x, y);
			if (y < display->map->size_y - 1)
				connect_v(display, x, y);
			if (display->node > 0)
			{
				display->p0 = &display->map->nodes[get_index(x, y, display->map)];
				draw_circle(display->g_img, *display->p0, display->node_rad, display->node_fill);
			}
			x++;
		}
		y++;
	}
}
