/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:11:40 by crabin            #+#    #+#             */
/*   Updated: 2025/09/18 20:20:05 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void isometric(t_point *p)
// {
// 	float temp_x;
// 	float temp_y;

// 	temp_x = p->x;
// 	temp_y = p->y;
	
// 	p->x = ((temp_x - temp_y) * cos(0.523599));
// 	p->y = ((temp_x + temp_y) * sin(0.523599) - p->z);
// }

void isometric_n(t_node *node)
{
	float temp_x;
	float temp_y;

	temp_x = node->x;
	temp_y = node->y;
	
	node->x = ((temp_x - temp_y) * cos(0.523599));
	node->y = ((temp_x + temp_y) * sin(0.523599) - node->z);
}

// move to rotation/drawing/rendering
// take display rotation parameters and pass to rotate point
// void res_point(t_display *display, t_point *p)
// {
// 	rotate_point(p, display->rx, display->ry, display->rz);
// 	isometric(p);

// 	p->pix_x = (int32_t)((display->offset_x) + (p->x * display->zoom_factor));
// 	p->pix_y = (int32_t)((display->offset_y) + (p->y * display->zoom_factor));
// 	//p_point(p);
// }

void resolve_node(t_display *display, t_node *node)
{
	node->x = node->x_orig;
	node->y = node->y_orig;
	node->z = node->z_orig * display->height_scale;
	rotate_node(node, display->rx, display->ry, display->rz);
	isometric_n(node);

	node->pix_x = (int32_t)((display->offset_x) + (node->x * display->zoom_factor));
	node->pix_y = (int32_t)((display->offset_y) + (node->y * display->zoom_factor));
}

// void gen_point(t_point *p, t_node *node)
// {
// 	p->x = (float)node->x_orig;
// 	p->y = (float)node->y_orig;
// 	p->z = (float)node->z_orig;
// 	p->colour = node->colour;
// }

/*draw a line between two horizontally adjacent nodes in map grid*/
void connect_h(t_display	*display, uint32_t x, uint32_t y)
{
	display->p0 = &display->map->nodes[get_index(x, y, display->map)];
	display->p1 = &display->map->nodes[get_index(x + 1, y, display->map)];
	draw_update(display);
}

/*draw a line between two vertically adjacent nodes in map grid*/
void connect_v(t_display	*display, uint32_t x, uint32_t y)
{
	display->p0 = &display->map->nodes[get_index(x, y, display->map)];
	display->p1 = &display->map->nodes[get_index(x, y + 1, display->map)];
	draw_update(display);
}


void update_grid(t_display	*display)
{
	int		index;
	int		size;

	size = (display->map->size_x * display->map->size_y);

	index = 0;
	while (index < size -1)
	{
		resolve_node(display, &display->map->nodes[index]);
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
