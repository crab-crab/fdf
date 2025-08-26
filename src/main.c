#include "fdf.h"
#include "stdio.h"

#define WIDTH 2000
#define HEIGHT 2000

static mlx_image_t	*g_img;

// int32_t ft_abs(int32_t num)
// {
// 	if (num < 0)
// 		num = -num;
// 	return (num);
// }

void    draw_line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
{
    int32_t dx;
    int32_t dy;
    int32_t stepx;
    int32_t stepy;
    int32_t err;
    int32_t e2;

    dx = (int32_t)x1 - (int32_t)x0;
    if (dx < 0)
        dx = -dx;
    dy = (int32_t)y1 - (int32_t)y0;
    if (dy < 0)
        dy = -dy;
    if (x0 < x1)
        stepx = 1;
    else
        stepx = -1;
    if (y0 < y1)
        stepy = 1;
    else
        stepy = -1;
    err = dx - dy;
    while (1)
    {
        mlx_put_pixel(g_img, x0, y0, 0xFFFFFFFF);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += stepx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += stepy;
        }
    }
}

void	hook(void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_P))
		mlx_delete_image(mlx, g_img);

	// Octave 1
	draw_line(0, 100, 500, 500); //YES
	// Octave 2
	draw_line(100, 0, 500, 500); //YES

	// Octave 3
	draw_line(100, 1000, 500, 500); // not working
	// Octave 4
	draw_line(0, 900, 500, 500); // not working

	// Octave 5
	draw_line(500, 500, 1000, 900); //YES
	// Octave 6
	draw_line(500, 500, 900, 1000); //YES

	// Octave 7
	draw_line(500, 500, 900, 0); // not working
	// Octave 8
	draw_line(500, 500, 1000, 100); // not working

	//crosshair
	draw_line(500, 0, 500, 500); // vertical top
	draw_line(0, 500, 500, 500); // horizontal left
	draw_line(500, 500, 500, 1000); // horizontal right
	draw_line(500, 500, 1000, 500); // vertical bottom

}


int32_t	main(void)
{
	mlx_t*    mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 2000, 2000);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}