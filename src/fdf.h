/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:08:39 by crabin            #+#    #+#             */
/*   Updated: 2025/09/10 15:02:13 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#include <fcntl.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"

# define BUFFER_SIZE 2048
# define PI	3.1416
# define WIDTH 2000
# define HEIGHT 2000

extern	t_proj ISO_PROJ;
extern	t_proj TOPDOWN;
extern	t_proj SIDE;
extern	t_proj DIMETRIC;
extern	t_proj PERSPECT;
extern	t_proj CABINET;

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
	int32_t		pix_x;
	int32_t		pix_y;
	uint32_t	colour;
} t_point;

typedef struct s_map
{
	uint32_t	size_x;
	uint32_t	size_y;
	int32_t		min_z;
	int32_t		max_z;
	t_node		**node_arr;

} t_map;

typedef struct s_line
{
	int32_t		dx;
    int32_t		dy;
    int32_t		stepx;
    int32_t		stepy;
    int32_t		err;
} t_line;

typedef struct s_display
{
	t_point		p0;
	t_point		p1;
	uint32_t	offset_x;
	uint32_t	offset_y;
	t_proj		projection;
	float		rx;
	float		ry;
	float		rz;
	float		zoom_factor;
	uint8_t		dynamic_zoom;
	uint8_t		node;
	uint8_t		node_fill;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*g_img;
} t_display;

typedef struct s_proj
{
	float		rx;
	float		ry;
	float		rz;
} t_proj;


typedef struct s_colour
{
	uint8_t	aa;
	uint8_t	rr;
	uint8_t	gg;
	uint8_t	bb;
} t_colour;

// map parsing
int32_t parse_map(char *filename, t_map *map);

// math
int32_t ft_abs(int32_t num);

// point generation
void res_point(t_display *display, t_point *p);
void gen_point(t_point *p, int32_t x, int32_t y, int32_t z, uint32_t colour);

// draw pixel
void draw_pixel(mlx_image_t	*g_img, int32_t pix_x, int32_t pix_y, int32_t colour)

// drawing line
void    draw_line(t_point p0, t_point p1, mlx_image_t	*g_img);
int32_t get_step(int32_t p0, int32_t p1);
void	draw_update(t_display	*display);

// drawing grid
void draw_grid(t_display	*display);

// hooks
void	test_hook(void* display);
void	grid_hook(void* display);

// colours
uint32_t get_colour(t_point p0, t_point p1, float weight);
float weight_scuffed(t_point start, t_point p0, t_line line);

// math
float dtor(float degrees);
float rtod(float radians);



// debugging
void p_display_val(t_display	*display);
void p_map(t_map *map);
void p_point(t_point *p);

#endif