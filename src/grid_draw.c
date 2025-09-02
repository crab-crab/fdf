/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:40 by crabin            #+#    #+#             */
/*   Updated: 2025/09/02 14:00:43 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void gen_point(t_point *p, uint32_t x, uint32_t y, int32_t z)
{
	p->x = (float)x;
	p->y = (float)y;
	p->z = (float)z;
}

void res_point(t_point *p)
{
	p->pix_x = p->x;
	p->pix_y = p->y;
}

void draw_grid(t_display	*display)
{
	uint32_t x;
	uint32_t y;
	// uint32_t size_y = display->map->size_y;
	// uint32_t size_x = display->map->size_x;

	y = 0;
	while (y < display->map->size_y - 1)
	{
		x = 0;
		while (x < display->map->size_x - 1)
		{
			gen_point(&(display->p0), x, y, display->map->node_arr[y][x].z);
			gen_point(&(display->p1), x + 1, y, display->map->node_arr[y][x + 1].z);
			draw_update(display);
			gen_point(&(display->p1), x, y + 1, display->map->node_arr[y + 1][x].z);
			draw_update(display);
			x++;
		}
		y++;
	}
}
