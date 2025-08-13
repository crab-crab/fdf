#include "fdf.h"
#include "stdio.h"

#define WIDTH 2000
#define HEIGHT 2000

static mlx_image_t	*g_img;

void u_swap(uint32_t *a, uint32_t *b)
{
	uint32_t temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void drawline_flat_mpos(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	float m;
	float c;
	int32_t x;
	int32_t y;

	m = (float)(y_1 - y_0) / (float)(x_1 - x_0);
	x = x_0;
	c = (y_0) - (m * x_0);
	while (x < x_1)
	{
		y = (int32_t)((m * x) + c);
		mlx_put_pixel(g_img, x, y, 0xFFFFFFFF);
		x++;
	}
}

void drawline_steep_mpos(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	float m;
	float c;
	int32_t x;
	int32_t y;

	m = (float)(y_1 - y_0) /  (float)(x_1 - x_0);
	y = y_0;
	c = (y_0) - (m * x_0);
	while (y < y_1)
	{
		x = (int32_t)((y - c) / (m));
		mlx_put_pixel(g_img, x, y, 0xFFFFFFFF);
		y++;
	}
}

void drawline_flat_mneg(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	float m;
	float c;
	int32_t x;
	int32_t y;

	m = (float)(y_1 - y_0) / (float)(x_1 - x_0);
	x = x_0;
	c = (y_0) - (m * x_0);
	while (x < x_1)
	{
		y = (int32_t)((m * x) + c);
		mlx_put_pixel(g_img, x, y, 0xFFFFFFFF);
		x++;
	}
}

void drawline_steep_mneg(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	float m;
	float c;
	int32_t x;
	int32_t y;

	m = (float)(y_1 - y_0) /  (float)(x_1 - x_0);
	y = y_0;
	c = (y_0) - (m * x_0);
	while (y > y_1)
	{
		x = (int32_t)((y - c) / (m));
		mlx_put_pixel(g_img, x, y, 0xFFFFFFFF);
		y--;
	}
}

void draw_v_axis(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int i;
	
	if (x_0 == x_1)
	{
		i = y_0;
		while (i < y_1)
		{
			mlx_put_pixel(g_img, x_0, i, 0xFFFFFFFF);
			i++;
		}
	}
}
void draw_h_axis(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	int i;
	
	if (y_0 == y_1)
	{
		i = x_0;
		while (i < x_1)
		{
			mlx_put_pixel(g_img, i, y_0, 0xFFFFFFFF);
			i++;
		}
	}
}

void drawline_mpos(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	float m;

	if (x_0 == x_1 || y_0 == y_1)
	{
		return ((void)printf("straightlineyo!\n"));
	}
	m = ((float)(y_1 - y_0) / (float)(x_1 - x_0));
	printf("line attempt (%d,%d)->(%d,%d)\n", x_0, y_0, x_1, y_1);
	if (0 <= m && m <= 1)
	{
		drawline_flat_mpos(x_0, y_0, x_1, y_1);
	}
	else if (1 < m && m <= 100000000)
	{
		drawline_steep_mpos(x_0, y_0, x_1, y_1);
	}
}

void drawline_mneg(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	float m;

	if (x_0 == x_1 || y_0 == y_1)
	{
		return ((void)printf("straightlineyo!\n"));
	}
	m = ((float)(y_1 - y_0) / (float)(x_1 - x_0));
	printf("line attempt (%d,%d)->(%d,%d)\n", x_0, y_0, x_1, y_1);
	if (0 > m && m >= -1)
	{
		drawline_flat_mneg(x_0, y_0, x_1, y_1);
	}
	else if (-1 > m)
	{
		drawline_steep_mneg(x_0, y_0, x_1, y_1);
	}
}

void drawline(uint32_t x_0, uint32_t y_0, uint32_t x_1, uint32_t y_1)
{
	float m;
	if (x_0 > x_1)
	{
		u_swap(&x_0, &x_1);
		u_swap(&y_0, &y_1);
	}
	m = ((float)(y_1 - y_0) / (float)(x_1 - x_0));
	//return ((void)printf("slope: %f", m));
	if (m >= 0)
	{
		drawline_mpos(x_0, y_0, x_1, y_1);
	}
	else
	{
		drawline_mneg(x_0, y_0, x_1, y_1);
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
	drawline(0, 0, 500, 500);
}


int32_t	main(void)
{
	mlx_t*    mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 128, 128);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}