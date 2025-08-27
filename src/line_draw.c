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

void    draw_line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
{
	t_line line;
	int32_t e2;

	line.dx = ft_abs((int32_t)x1 - (int32_t)x0);
	line.dy = ft_abs((int32_t)y1 - (int32_t)y0);
	line.stepx = get_step(x0, x1);
	line.stepy = get_step(y0, y1);
	line.err = line.dx - line.dy;
	while (x0 != x1 || y0 != y1)
    {
        mlx_put_pixel(g_img, x0, y0, 0xFFFFFFFF);
		e2 = 2 * line.err;
		if (e2 > -line.dy)
		{
			line.err -= line.dy;
			x0 += line.stepx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			y0 += line.stepy;
		}
	}
	mlx_put_pixel(g_img, x0, y0, 0xFFFFFFFF);
}