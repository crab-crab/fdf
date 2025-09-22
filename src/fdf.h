/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:08:39 by crabin            #+#    #+#             */
/*   Updated: 2025/09/22 18:24:24 by crabin           ###   ########.fr       */
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

# define BUFFER_SIZE 40480
# define PI	3.1416
# define WIDTH 2000
# define HEIGHT 2000
# define BORDER 50
# define ROT_STEP 0.06
# define TRAN_STEP 10
# define ZOOM_STEP 1.05
# define NODE_RADIUS 5
# define HEIGHT_SCALE 0.2
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
	char		filename[50];
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
	int8_t		node_f;
	uint32_t	node_rad;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	mlx_image_t	*text_img;
} t_display;

typedef struct s_line
{
	
	int32_t		start_x;
	int32_t		start_y;
	int32_t		pix_x;
	int32_t		pix_y;
	int32_t		dx;
    int32_t		dy;
    int32_t		stepx;
    int32_t		stepy;
    int32_t		err;
} t_line;

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

// rotation
void rotate_node(t_node *node, t_display *display);

// projection
void resolve_node(t_display *display, t_node *node);

// draw pixel
void draw_pixel(mlx_image_t	*g_img, int32_t pix_x, int32_t pix_y, uint32_t colour);
int valid_point(t_node p0);

// draw
void    	draw_line(t_node p_start, t_node p_end, mlx_image_t	*g_img);
void		draw_circle(mlx_image_t *g_img, t_node p, int32_t r, uint8_t fill);
void		draw_grid(t_display	*display);

// colours
uint32_t	get_colour(t_node p0, t_node p1, float weight);
void		set_rgb(uint32_t c, t_node *node);
uint32_t	blend_rgb(uint8_t rr, uint8_t gg, uint8_t bb, uint8_t aa);
float 		get_weight_2(t_line line);

// math
uint8_t clampf_u8(float value);
int32_t ft_abs(int32_t num);
float dtor(float degrees);
float rtod(float radians);

// user input
void user_input(t_display	*display);

// interface
void draw_info(t_display *display);


// utils
char		*ft_strlchr(char *s, int c, size_t l);
uint32_t	ft_hextoi(const char *nptr);
int32_t 	ft_size(char **arr);
int32_t		count_cells(char *txt, char c);
uint32_t	get_index(int32_t x, int32_t y, t_map *map);

// debugging
void p_display_val(t_display	*display);
void p_map(t_map *map);


#endif