/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:08:39 by crabin            #+#    #+#             */
/*   Updated: 2025/08/27 15:26:24 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_node
{
	int32_t		z;
	uint32_t	colour;
} t_node;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	uint32_t	pix_x;
	uint32_t	pix_y;
	uint32_t	colour;
} t_point;

typedef struct s_map
{
	uint32_t	size_x;
	uint32_t	size_y;
	t_node		**node_arr;

} t_map;

typedef struct s_line
{
	int32_t dx;
    int32_t dy;
    int32_t stepx;
    int32_t stepy;
    int32_t err;
} t_line;

typedef struct s_display
{
	t_point		p1;
	t_point		p2;
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*g_img;

} t_display;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

void    draw_line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1);

#endif