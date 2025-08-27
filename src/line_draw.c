/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:00:46 by crabin            #+#    #+#             */
/*   Updated: 2025/08/27 13:01:22 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t ft_abs(int32_t num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int32_t get_step(int32_t p0, int32_t p1)
{
	int32_t step;
	
	if (p0 < p1)
		step = 1;
	else
		step = -1;
	return (step);
}

uint32_t get_colour(void)
{
	return (0xFFFFFFFF);
}

void    draw_line(t_point p0, t_point p1, mlx_image_t	*g_img)
{
	t_line line;
	int32_t e2;

	line.dx = ft_abs((int32_t)p1.x - (int32_t)p0.x);
	line.dy = ft_abs((int32_t)p1.y - (int32_t)p0.y);
	line.stepx = get_step(p0.x, p1.x);
	line.stepy = get_step(p0.y, p1.y);
	line.err = line.dx - line.dy;
	while (p0.x != p1.x || p0.y != p1.y)
    {
        mlx_put_pixel(g_img, p0.x, p0.y, get_colour());
		e2 = 2 * line.err;
		if (e2 > -line.dy)
		{
			line.err -= line.dy;
			p0.x += line.stepx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			p0.x += line.stepy;
		}
	}
	mlx_put_pixel(g_img, p0.x, p0.y, get_colour());
}
