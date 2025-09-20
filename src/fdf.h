/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:08:39 by crabin            #+#    #+#             */
/*   Updated: 2025/09/19 18:57:05 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#include <float.h>
#include <fcntl.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"

# define BUFFER_SIZE 2048
# define PI	3.1416
# define WIDTH 2000
# define HEIGHT 2000
# define BORDER 50
# define ROT_STEP 0.06
# define TRAN_STEP 10
# define ZOOM_STEP 1.05
# define NODE_RADIUS 5
# define HEIGHT_SCALE 1
# define ISOMETRIC 1
# define TOPDOWN 2
# define DIMETRIC 3
# define CABINET 4
# define PATH_MAP "test_maps/"

typedef struct s_node
{
	int32_t		x_orig;
	int32_t		y_orig;
	int32_t		z_orig;
	float		x;
	float		y;
	float		z;
	float		pix_x;
	float		pix_y;
	uint32_t 	colour;
	uint8_t		aa;
	uint8_t		rr;
	uint8_t		gg;
	uint8_t		bb;
} t_node;

typedef struct s_map
{
	int32_t		size_x;
	int32_t		size_y;
	int32_t		min_z;
	int32_t		max_z;
	t_node		*nodes;
} t_map;

typedef struct s_display
{
	t_node		*p0;
	t_node		*p1;
	int32_t		offset_x;
	int32_t		offset_y;
	int16_t		proj;
	float		rx;
	float		ry;
	float		rz;
	float		cos_rx;
	float		sin_rx;
	float		cos_ry;
	float		sin_ry;
	float		cos_rz;
	float		sin_rz;
	float		zoom_factor;
	float		height_scale;
	int8_t		dynamic_zoom;
	int8_t		node;
	int8_t		node_fill;
	uint32_t	node_rad;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*g_img;
} t_display;

typedef struct s_point // fold into line
{
	int32_t		pix_x;
	int32_t		pix_y;
} t_point;

typedef struct s_line // add start end?
{
	int32_t		dx;
    int32_t		dy;
    int32_t		stepx;
    int32_t		stepy;
    int32_t		err;
} t_line;

typedef struct s_colour //redundant
{
	uint8_t	rr;
	uint8_t	gg;
	uint8_t	bb;
	uint8_t	aa;
} t_colour;

// map parsing
int32_t parse_map(char *filename, t_map *map);

// math
int32_t ft_abs(int32_t num);

// display
void reset_display(t_display	*display);
void free_display(t_display	**display);
t_display	*init_display(t_map *map);
void wipe_screen(t_display	*display, uint32_t colour);

// Data Structure
uint32_t get_index(int32_t x, int32_t y, t_map *map);

// point generation
void res_point(t_display *display, t_point *p);
void gen_point(t_point *p, t_node *node);

// rotation
void rotate_point(t_point *p, float rx, float ry, float rz);
void rotate_node(t_node *node, t_display *display);

// projection
void isometric_n(t_node *node);
void resolve_node(t_display *display, t_node *node);

// draw pixel
void draw_pixel(mlx_image_t	*g_img, int32_t pix_x, int32_t pix_y, uint32_t colour);

// draw
void    	draw_line(t_node p_start, t_node p_end, mlx_image_t	*g_img);
int32_t 	get_step(int32_t p0, int32_t p1);
void		draw_update(t_display	*display);
void		draw_circle(mlx_image_t *g_img, t_node p, int32_t r, uint8_t fill);
void		draw_grid(t_display	*display);

// hooks
void	test_hook(void* display);
void	grid_hook(void* display);

// colours
uint32_t	get_colour(t_node p0, t_node p1, float weight);
float		get_weight(t_node start, t_point current, t_node end);
void		set_rgb(uint32_t c, t_node *node);
uint32_t	blend_rgb_node(t_node *node);
uint32_t	blend_rgb(uint8_t rr, uint8_t gg, uint8_t bb, uint8_t aa);
float		weight_scuffed(t_point start, t_point p0, t_line line);

// math
float dtor(float degrees);
float rtod(float radians);

// user input
void user_input(t_display	*display);


// debugging
void p_display_val(t_display	*display);
void p_map(t_map *map);
void p_point(t_point *p);


#endif