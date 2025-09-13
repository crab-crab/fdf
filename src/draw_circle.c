

#include "fdf.h"

void simple_line_h(mlx_image_t *g_img, int32_t x, int32_t y, int32_t len, uint32_t colour)
{
	while (len != 0)
	{
		draw_pixel(g_img, x, y, colour);
		x++;
		len--;
	}
}

void circle_fill(mlx_image_t *g_img, t_point p, int32_t x, int32_t y)
{
	int32_t cx;
	int32_t cy;

	cx = p.pix_x;
	cy = p.pix_y;
	simple_line_h(g_img, cx - x, cy + y, (2 * x), p.colour);
	simple_line_h(g_img, cx - x, cy - y, (2 * x), p.colour);
	simple_line_h(g_img, cx - y, cy + x, (2 * y), p.colour);
	simple_line_h(g_img, cx - y, cy - x, (2 * y), p.colour);
}

void circle_points(mlx_image_t *g_img, t_point p, int32_t x, int32_t y)
{
	int32_t cx;
	int32_t cy;

	cx = p.pix_x;
	cy = p.pix_y;
	draw_pixel(g_img, cx + x, cy + y, p.colour);
	draw_pixel(g_img, cx - x, cy + y, p.colour);
	draw_pixel(g_img, cx + x, cy - y, p.colour);
	draw_pixel(g_img, cx - x, cy - y, p.colour);
	draw_pixel(g_img, cx + y, cy + x, p.colour);
	draw_pixel(g_img, cx - y, cy + x, p.colour);
	draw_pixel(g_img, cx + y, cy - x, p.colour);
	draw_pixel(g_img, cx - y, cy - x, p.colour);
}

/*
Draws circle outline by plotting 8 rotationally symetrical points for 45deg
-> trying to connect points and draw 4 horizontal lines instead
*/
void draw_circle(mlx_image_t *g_img, t_point p, int32_t r, uint8_t fill)
{
	int32_t x;
	int32_t y;
	int32_t d;

	x = 0;
	y = r;
	d = 1 - r;
	while (x <= y)
	{
		if (fill == 1)
			circle_fill(g_img, p, x, y);
		else
			circle_points(g_img, p, x, y)
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y-= 1;
		}
		x += 1;
	}
}
