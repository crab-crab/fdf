/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:00:46 by crabin            #+#    #+#             */
/*   Updated: 2025/09/14 14:32:33 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t get_step(int32_t p0, int32_t p1)
{
	int32_t step;
	
	if (p0 < p1)
		step = 1;
	else
		step = -1;
	return (step);
}

void init_line(t_line *line, t_point p0, t_point p1)
{
	line->dx = ft_abs((int32_t)p1.pix_x - (int32_t)p0.pix_x);
	line->dy = ft_abs((int32_t)p1.pix_y - (int32_t)p0.pix_y);
	line->stepx = get_step(p0.pix_x, p1.pix_x);
	line->stepy = get_step(p0.pix_y, p1.pix_y);
	line->err = line->dx - line->dy;
}

void draw_pixel(mlx_image_t	*g_img, int32_t pix_x, int32_t pix_y, int32_t colour)
{
	if (pix_x >= 0 && pix_x <= WIDTH && pix_y >= 0 && pix_y <= HEIGHT)
		mlx_put_pixel(g_img, pix_x, pix_y, colour);

}

void    draw_line(t_point p0, t_point p1, mlx_image_t	*g_img)
{
	t_line line;
	int32_t e2;
	t_point start;

	start.pix_x = p0.pix_x;
	start.pix_y = p0.pix_y;
	init_line(&line, p0, p1);
	while (p0.pix_x != p1.pix_x || p0.pix_y != p1.pix_y)
    {
        draw_pixel(g_img, p0.pix_x, p0.pix_y, get_colour(p0, p1, weight_scuffed(start, p0, line)));
		e2 = 2 * line.err;
		if (e2 > -line.dy)
		{
			line.err -= line.dy;
			p0.pix_x += line.stepx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			p0.pix_y += line.stepy;
		}
	}
	draw_pixel(g_img, p0.pix_x, p0.pix_y, get_colour(p0, p1, weight_scuffed(start, p0, line)));
}

int valid_point(t_point p0)
{
	return (1); //debug
	if (p0.pix_x >= 0 && p0.pix_x <= WIDTH && p0.pix_y >= 0 && p0.pix_y <= HEIGHT)
		return (1);
	else
		return (0);
}

void	draw_update(t_display	*display)
{
	
	res_point(display, &(display->p0));
	res_point(display, &(display->p1));
	
	if (valid_point(display->p0) && valid_point(display->p1))
	{
		draw_line(display->p0, display->p1, display->g_img);
	}
	else
	{
		printf("! Pixel Out of Bounds !\n");
	}
}