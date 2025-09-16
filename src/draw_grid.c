/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:40 by crabin            #+#    #+#             */
/*   Updated: 2025/09/16 15:58:54 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric(t_point *p)
{
	int32_t temp_x;
	int32_t temp_y;

	temp_x = p->x;
	temp_y = p->y;
	
	p->x = ((temp_x - temp_y) * cos(0.523599));
	p->y = ((temp_x + temp_y) * sin(0.523599) - p->z);
}

// move to rotation/drawing/rendering
// take display rotation parameters and pass to rotate point
void res_point(t_display *display, t_point *p)
{
	//isometric(p);
	rotate_point(p, display->rx, display->ry, display->rz);

	p->pix_x = (int32_t)((display->offset_x) + (p->x * display->zoom_factor));
	p->pix_y = (int32_t)((display->offset_y) + (p->y * display->zoom_factor));
	//p_point(p);
}

void gen_point(t_point *p, int32_t x, int32_t y, int32_t z, uint32_t colour)
{
	p->x = (float)x;
	p->y = (float)y;
	p->z = (float)z;
	p->colour = colour;
}

/*draw a line between two horizontally adjacent nodes in map grid*/
void connect_h(t_display	*display, uint32_t x, uint32_t y)
{
	gen_point(&(display->p0), x, y, 
		display->map->node_arr[y][x].z, 
		display->map->node_arr[y][x].colour);
	gen_point(&(display->p1), x + 1, y, 
		display->map->node_arr[y][x + 1].z, 
		display->map->node_arr[y][x + 1].colour);
	draw_update(display);
}

/*draw a line between two vertically adjacent nodes in map grid*/
void connect_v(t_display	*display, uint32_t x, uint32_t y)
{
	gen_point(&(display->p0), x, y, 
		display->map->node_arr[y][x].z, 
		display->map->node_arr[y][x].colour);
	gen_point(&(display->p1), x, y + 1, 
		display->map->node_arr[y + 1][x].z, 
		display->map->node_arr[y + 1][x].colour);
	draw_update(display);
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

	y = 0;
	while (y < display->map->size_y)
	{
		x = 0;
		while (x < display->map->size_x)
		{
			
			if (x < display->map->size_x - 1)
				connect_h(display, x, y);
			if (y < display->map->size_y - 1)
				connect_v(display, x, y);
			if (display->node > 0)
			{
				draw_circle(display->g_img, display->p0, display->node_rad, display->node_fill);
			}
			x++;
		}
		y++;
	}
}
