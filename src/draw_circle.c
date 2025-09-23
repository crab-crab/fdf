/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:28:11 by crabin            #+#    #+#             */
/*   Updated: 2025/09/23 16:36:06 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	simple_line_h(mlx_image_t *g_img, int32_t xy[2],
					int32_t len, uint32_t colour)
{
	while (len != 0)
	{
		draw_pixel(g_img, xy[0], xy[1], colour);
		xy[0]++;
		len--;
	}
}

void	circle_fill(mlx_image_t *g_img, t_node p, int32_t x, int32_t y)
{
	int32_t	cx;
	int32_t	cy;
	int32_t	xy[2];

	cx = p.pix_x;
	cy = p.pix_y;
	xy[0] = cx - x;
	xy[1] = cy + y;
	simple_line_h(g_img, xy, (2 * x), p.colour);
	xy[0] = cx - x;
	xy[1] = cy - y;
	simple_line_h(g_img, xy, (2 * x), p.colour);
	xy[0] = cx - y;
	xy[1] = cy + x;
	simple_line_h(g_img, xy, (2 * y), p.colour);
	xy[0] = cx - y;
	xy[1] = cy - x;
	simple_line_h(g_img, xy, (2 * y), p.colour);
}

void	circle_points(mlx_image_t *g_img, t_node p, int32_t x, int32_t y)
{
	int32_t	cx;
	int32_t	cy;

	cx = p.pix_x;
	cy = p.pix_y;
	draw_pixel(g_img, cx + x, cy + y, p.colour);
	draw_pixel(g_img, cx - x, cy + y, p.colour);
	draw_pixel(g_img, cx + x, cy - y, p.colour);
	draw_pixel(g_img, cx - x, cy - y, p.colour);
	draw_pixel(g_img, cx + y, cy + x, p.colour);
	draw_pixel(g_img, cx - y, cy + x, p.colour);
	draw_pixel(g_img, cx + y, cy - x, p.colour);
	draw_pixel(g_img, cx - y, cy - x, p.colour);
}

/*
Draws circle outline by plotting 8 rotationally symetrical points for 45deg
-> trying to connect points and draw 4 horizontal lines instead
*/
void	draw_circle(mlx_image_t *g_img, t_node p, int32_t r, uint8_t fill)
{
	int32_t	x;
	int32_t	y;
	int32_t	d;

	x = 0;
	y = r;
	d = 1 - r;
	while (x <= y)
	{
		if (fill == 1)
			circle_fill(g_img, p, x, y);
		else
			circle_points(g_img, p, x, y);
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y -= 1;
		}
		x += 1;
	}
}
