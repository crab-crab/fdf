/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:00:46 by crabin            #+#    #+#             */
/*   Updated: 2025/09/25 14:28:50 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	get_step(int32_t p0, int32_t p1)
{
	int32_t	step;

	if (p0 < p1)
		step = 1;
	else
		step = -1;
	return (step);
}

void	init_line(t_line *line, t_node p0, t_node p1)
{
	line->dx = ft_abs((int32_t)p1.pix_x - (int32_t)p0.pix_x);
	line->dy = ft_abs((int32_t)p1.pix_y - (int32_t)p0.pix_y);
	line->stepx = get_step(p0.pix_x, p1.pix_x);
	line->stepy = get_step(p0.pix_y, p1.pix_y);
	line->err = line->dx - line->dy;
	line->pix_x = (int32_t)p0.pix_x;
	line->pix_y = (int32_t)p0.pix_y;
	line->start_x = (int32_t)p0.pix_x;
	line->start_y = (int32_t)p0.pix_y;
}

inline void	draw_pixel(mlx_image_t	*g_img, int32_t pix_x,\
					int32_t pix_y, uint32_t colour)
{
	if (pix_x >= 0 + BORDER && pix_x <= WIDTH - BORDER
		&& pix_y >= 0 + BORDER && pix_y <= HEIGHT - BORDER)
		mlx_put_pixel(g_img, (uint32_t)pix_x, (uint32_t)pix_y, colour);
}

void	draw_line(t_node p_start, t_node p_end, mlx_image_t	*g_img)
{
	t_line	line;
	int32_t	e2;

	init_line(&line, p_start, p_end);
	while ((int32_t)line.pix_x != (int32_t)p_end.pix_x
		|| (int32_t)line.pix_y != (int32_t)p_end.pix_y)
	{
		draw_pixel(g_img, line.pix_x, line.pix_y,
			get_colour(p_start, p_end, get_weight_2(line)));
		e2 = 2 * line.err;
		if (e2 > -line.dy)
		{
			line.err -= line.dy;
			line.pix_x += line.stepx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			line.pix_y += line.stepy;
		}
	}
}

int	valid_point(t_node p0)
{
	if (p0.pix_x >= 0 && p0.pix_x <= WIDTH
		&& p0.pix_y >= 0 && p0.pix_y <= HEIGHT)
		return (1);
	else
		return (0);
}
