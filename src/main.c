#include "fdf.h"
#include "stdio.h"

#define WIDTH 2000
#define HEIGHT 2000

static mlx_image_t	*g_img;

void line_oct1(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int32_t dx;
	int32_t dy;
	int32_t	p;
	
	dx = x_1 - x_0;
	dy = y_1 - y_0;
	p = (2 * dy) - dx;
	while (x_0 <= x_1)
	{
		mlx_put_pixel(g_img, x_0, y_0, 0xFFFFFFFF);
		if (p >= 0)
		{
			y_0++;
			p-= 2 * dx;
		}
		p += 2 * dy;
		x_0++;
	}
}

void line_oct2(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int32_t dx;
	int32_t dy;
	int32_t	p;

	dx = x_1 - x_0;
	dy = y_1 - y_0;
	p = (2 * dx) - dy;
	while (y_0 <= y_1)
	{
		mlx_put_pixel(g_img, x_0, y_0, 0xFFFFFFFF);
		if (p >= 0)
		{
			x_0++;
			p-= 2 * dy;
		}
		p += 2 * dx;
		y_0++;
	}
}

void line_oct3(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int32_t dx;
	int32_t dy;
	int32_t	p;

	dx = x_1 - x_0;
	dy = -(y_1 - y_0);
	p = (2 * dx) - dy;
	while (y_0 >= y_1)
	{
		mlx_put_pixel(g_img, x_0, y_0, 0xFFFFFFFF);
		if (p >= 0)
		{
			x_0++;
			p-= 2 * dy;
		}
		p += 2 * dx;
		y_0--;
	}
}

void line_oct4(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int32_t dx;
	int32_t dy;
	int32_t	p;
	
	dx = x_1 - x_0;
	dy = y_0 - y_1;
	p = (2 * dy) - dx;
	while (x_0 <= x_1)
	{
		mlx_put_pixel(g_img, x_0, y_0, 0xFFFFFFFF);
		if (p >= 0)
		{
			y_0--;
			p -= 2 * dx;
		}
		p += 2 * dy;
		x_0++;
	}
}

void line_oct5(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int32_t dx;
	int32_t dy;
	int32_t	p;
	
	dx = x_0 - x_1;
	dy = y_1 - y_0;
	p = (2 * dy) - dx;
	while (x_0 >= x_1)
	{
		mlx_put_pixel(g_img, x_0, y_0, 0xFFFFFFFF);
		if (p >= 0)
		{
			y_0++;
			p -= 2 * dx;
		}
		p += 2 * dy;
		x_0--;
	}
}

void line_oct6(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int32_t dx;
	int32_t dy;
	int32_t	p;
	
	dx = x_0 - x_1;
	dy = y_1 - y_0;
	p = (2 * dx) - dy;
	while (y_0 <= y_1)
	{
		mlx_put_pixel(g_img, x_0, y_0, 0xFFFFFFFF);
		if (p >= 0)
		{
			x_0--;
			p -= 2 * dy;
		}
		p += 2 * dx;
		y_0++;
	}
}

void line_oct7(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int32_t dx;
	int32_t dy;
	int32_t	p;

	dx = x_0 - x_1;
	dy = y_0 - y_1;
	p = (2 * dx) - dy;
	while (y_0 >= y_1)
	{
		// if (!(x_0 < 0 || x_0 > WIDTH || y_0 < 0 || y_0 > HEIGHT))
		mlx_put_pixel(g_img, x_0, y_0, 0xFFFFFFFF);
		if (p >= 0)
		{
			x_0--;
			p -= 2 * dy;
		}
		p += 2 * dx;
		y_0--;
	}
}

void line_oct8(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int32_t dx;
	int32_t dy;
	int32_t	p;
	
	dx = x_0 - x_1;
	dy = y_0 - y_1;
	p = (2 * dy) - dx;
	while (x_0 >= x_1)
	{
		mlx_put_pixel(g_img, x_0, y_0, 0xFFFFFFFF);
		if (p >= 0)
		{
			y_0--;
			p -= 2 * dx;
		}
		p += 2 * dy;
		x_0--;
	}
}

/*
Unified line drawing equation with logic to choose between the relevant
sub-sector equations.

-	Quadrant 1 (right and up, +x/+y) - Oct1 & Oct2
-	Quadrant 2 (right and down, +x/-y) - Oct3 & Oct4
-	Quadrant 3 (left and up, -x/+y) - Oct5 & Oct6
-	Quadrant 4 (left and down, -x/-y) - Oct7 & Oct8

*/
void draw_line(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int32_t dx;
	int32_t dy;

	dx = x_0 - x_1;
	dy = y_0 - y_1;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	if (dx >= 0 && dy >= 0)
	{
		if (dy <= dx)
			return(line_oct1(x_0, y_0, x_1, y_1));
		line_oct2(x_0, y_0, x_1, y_1);
	}
	else if (dx >= 0 && dy < 0)
	{
		if (-dy >= dx)
			return(line_oct3(x_0, y_0, x_1, y_1));
		line_oct4(x_0, y_0, x_1, y_1);
	}
	else if (dx < 0 && dy >= 0)
	{
		if (dy <= -dx)
			return(line_oct5(x_0, y_0, x_1, y_1));
		line_oct6(x_0, y_0, x_1, y_1);
	}
	else
	{
		if (-dy >= -dx)
			return(line_oct7(x_0, y_0, x_1, y_1));
		line_oct8(x_0, y_0, x_1, y_1);
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
	draw_line(100, 1000, 500, 500); //YES
	// Octave 4
	draw_line(0, 900, 500, 500); //YES

	// Octave 5
	draw_line(500, 500, 1000, 900); //YES
	// Octave 6
	draw_line(500, 500, 900, 1000); //YES

	//draw_line(500, 500, 1000, 0);
	// Octave 7
	draw_line(500, 500, 900, 0);
	// Octave 8
	draw_line(500, 500, 1000, 100);

	//crosshair
	draw_line(500, 0, 500, 500); // vertical top
	draw_line(0, 500, 500, 500); // horizontal left
	draw_line(500, 500, 500, 1000); // horizontal right
	draw_line(500, 500, 1000, 500); // vertical bottom
	//draw_line(0, 0, 400, 500);
	//draw_line(0, 0, 500, 400); // non-steep  0<m<1
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