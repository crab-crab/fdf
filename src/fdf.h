/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:08:39 by crabin            #+#    #+#             */
/*   Updated: 2025/09/15 17:44:55 by crabin           ###   ########.fr       */
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
# define ROT_STEP 0.001
# define TRAN_STEP 10
# define ZOOM_STEP 1.2
# define PATH_MAP "testmaps/"

# define BLACK 0x000000FF;
# define WHITE 0xFFFFFFFF;

typedef struct s_proj
{
	float		rx;
	float		ry;
	float		rz;
} t_proj;

# define ISO_PROJ		(t_proj){0.61548, -0.785398, 0}
# define TOPDOWN		(t_proj){0, 0, 0}
# define SIDE1			(t_proj){0, 1.5708, 0}
# define SIDE2			(t_proj){1.5708, 0, 0}
# define DIMETRIC		(t_proj){-0.523599, 0.785398, 0}
# define PERSPECT 		(t_proj){-0.523599, 0.523599, 0}
# define CABINET		(t_proj){0, 0.785398, 0}

//const t_proj	PROJECTIONS[7] = {ISO_PROJ, TOPDOWN, SIDE1, SIDE2, DIMETRIC, PERSPECT, CABINET};

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



typedef struct s_colour
{
	uint8_t	aa;
	uint8_t	rr;
	uint8_t	gg;
	uint8_t	bb;
} t_colour;

// // projections
// extern const	t_proj ISO_PROJ;
// extern const	t_proj TOPDOWN;
// extern const	t_proj SIDE1;
// extern const	t_proj SIDE2;
// extern const	t_proj DIMETRIC;
// extern const	t_proj PERSPECT;
// extern const	t_proj CABINET;

// map parsing
int32_t parse_map(char *filename, t_map *map);

// math
int32_t ft_abs(int32_t num);

// point generation
void res_point(t_display *display, t_point *p);
void gen_point(t_point *p, int32_t x, int32_t y, int32_t z, uint32_t colour);

// rotation
void rotate_point(t_point *p, float rx, float ry, float rz);

// draw pixel
void draw_pixel(mlx_image_t	*g_img, int32_t pix_x, int32_t pix_y, int32_t colour);

// draw
void    draw_line(t_point p0, t_point p1, mlx_image_t	*g_img);
int32_t get_step(int32_t p0, int32_t p1);
void	draw_update(t_display	*display);
void	draw_circle(mlx_image_t *g_img, t_point p, int32_t r, uint8_t fill);
void	draw_grid(t_display	*display);

// hooks
void	test_hook(void* display);
void	grid_hook(void* display);

// colours
uint32_t get_colour(t_point p0, t_point p1, float weight);
float weight_scuffed(t_point start, t_point p0, t_line line);

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