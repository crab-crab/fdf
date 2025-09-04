/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:40 by crabin            #+#    #+#             */
/*   Updated: 2025/09/04 17:56:39 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void res_point(t_display *display, t_point *p)
{
	p->pix_x = (uint32_t)((display->offset_x) + (p->x * display->zoom_factor));
	p->pix_y = (uint32_t)((display->offset_y) + (p->y * display->zoom_factor));
}

void gen_point(t_point *p, uint32_t x, uint32_t y, int32_t z, uint32_t colour)
{
	p->x = (float)x;
	p->y = (float)y;
	p->z = (float)z;
	p->colour = colour;
}

void draw_grid(t_display	*display)
{
	uint32_t x;
	uint32_t y;

	y = 0;
	while (y < display->map->size_y)
	{
		x = 0;
		while (x < display->map->size_x)
		{
			gen_point(&(display->p0), x, y, display->map->node_arr[y][x].z, display->map->node_arr[y][x].colour);
			if (x < display->map->size_x - 1)
			{
				gen_point(&(display->p1), x + 1, y, display->map->node_arr[y][x + 1].z, display->map->node_arr[y][x + 1].colour);
				draw_update(display);
			}
			if (y < display->map->size_y - 1)
			{
				gen_point(&(display->p1), x, y + 1, display->map->node_arr[y + 1][x].z, display->map->node_arr[y + 1][x].colour);
				draw_update(display);
			}
			x++;
		}
		y++;
	}
}
