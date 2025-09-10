/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:40 by crabin            #+#    #+#             */
/*   Updated: 2025/09/10 15:06:56 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric(t_point *p)
{
	p->x = ((p->x - p->y) * cos(0.523599));
	p->y = ((p->x + p->y) * sin(0.523599) - p->z);
}

void res_point(t_display *display, t_point *p)
{
	//isometric(p);
	//p_point(p);
	p->pix_x = (int32_t)((display->offset_x) + (p->x * display->zoom_factor));
	p->pix_y = (int32_t)((display->offset_y) + (p->y * display->zoom_factor));
	p_point(p);
}

void gen_point(t_point *p, int32_t x, int32_t y, int32_t z, uint32_t colour)
{
	p->x = (float)x;
	p->y = (float)y;
	p->z = (float)z;
	if (colour != 0)
		p->colour = colour;
	else
		p->colour = 0x80FFFF;
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
			
			if (x < display->map->size_x - 1)
			{
				gen_point(&(display->p0), x, y, display->map->node_arr[y][x].z, display->map->node_arr[y][x].colour);
				gen_point(&(display->p1), x + 1, y, display->map->node_arr[y][x + 1].z, display->map->node_arr[y][x + 1].colour);
				draw_update(display);
			}
			if (y < display->map->size_y - 1)
			{
				gen_point(&(display->p0), x, y, display->map->node_arr[y][x].z, display->map->node_arr[y][x].colour);
				gen_point(&(display->p1), x, y + 1, display->map->node_arr[y + 1][x].z, display->map->node_arr[y + 1][x].colour);
				draw_update(display);
			}
			x++;
		}
		y++;
	}
}
