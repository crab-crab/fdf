#include "fdf.h"

void set_point(t_display	*display, uint32_t x, uint32_t y, uint32_t p)
{
	if (p == 0)
	{
		display->p0.pix_x = (float)x;
		display->p0.pix_y = (float)y;
	}
	else
	{
		display->p1.pix_x = (float)x;
		display->p1.pix_y = (float)y;
	}
}

// void	test_hook(void* display)
// {

// 	set_point(display, 500, 500, 1);
// 	// Octave 1
// 	set_point(display, 0, 200, 0);
// 	draw_update(display);
// 	set_point(display, 0, 100, 0);
// 	draw_update(display);

// 	// Octave 2
// 	set_point(display, 200, 0, 0);
// 	draw_update(display);
// 	set_point(display, 100, 0, 0);
// 	draw_update(display);

// 	// Octave 3
// 	set_point(display, 100, 1000, 0);
// 	draw_update(display);
// 	set_point(display, 200, 1000, 0);
// 	draw_update(display);

// 	// Octave 4
// 	set_point(display, 0, 900, 0);
// 	draw_update(display);
// 	set_point(display, 0, 800, 0);
// 	draw_update(display);

// 	set_point(display, 500, 500, 0);
// 	// Octave 5
// 	set_point(display, 1000, 900, 1);
// 	draw_update(display);
// 	set_point(display, 1000, 800, 1);
// 	draw_update(display);

// 	// Octave 6
// 	set_point(display, 900, 1000, 1);
// 	draw_update(display);
// 	set_point(display, 800, 1000, 1);
// 	draw_update(display);

// 	// Octave 7
// 	set_point(display, 900, 0, 1);
// 	draw_update(display);
// 	set_point(display, 800, 0, 1);
// 	draw_update(display);

// 	// Octave 8
// 	set_point(display, 1000, 100, 1);
// 	draw_update(display);
// 	set_point(display, 1000, 200, 1);
// 	draw_update(display);

// 	//crosshair
// 	set_point(display, 500, 1000, 1); // horizontal right
// 	draw_update(display);
// 	set_point(display, 1000, 500, 1); // vertical bottom
// 	draw_update(display);
// 	set_point(display, 500, 500, 1);
// 	set_point(display, 500, 0, 0); // vertical top
// 	draw_update(display);
// 	set_point(display, 0, 500, 0); // horizontal left
// 	draw_update(display);
// }

void drw_triangle(t_display	*display, t_point p0, t_point p1, t_point center)
{
	uint32_t x;
	uint32_t y;
	uint32_t step_x;
	uint32_t step_y;

	x = p0.pix_x;
	y = p0.pix_y;
	step_x = get_step(p0.pix_x, p1.pix_x);
	step_y = get_step(p0.pix_y, p1.pix_y);
	set_point(display, center.pix_x, center.pix_y, 0);

	while (x < WIDTH && y < WIDTH && x >= 0 && y >= 0)
	{
		set_point(display, x, y, 1);
		draw_update(display);
		x += step_x;
		y += step_y;
	}

}

void	grid_hook(void* display)
{
	draw_grid(display);
}

void	test_hook(void* display)
{
	t_point p0;
	t_point p1;
	t_point center;

	center.pix_x = 1000, center.pix_y = 1000;

	p0.pix_x = 1, p0.pix_y = 999;
	p1.pix_x = 999, p1.pix_y = 1999;	
	drw_triangle(display, p0, p1, center); // works kinda

	p0.pix_x = 1, p0.pix_y = 999;
	p1.pix_x = 999, p1.pix_y = 1;
	drw_triangle(display, p0, p1, center); // doesnt work

	p0.pix_x = 999, p0.pix_y = 1;
	p1.pix_x = 1999, p1.pix_y = 999;
	drw_triangle(display, p0, p1, center); // works kinda

	p0.pix_x = 999, p0.pix_y = 1999;
	p1.pix_x = 1999, p1.pix_y = 999;
	drw_triangle(display, p0, p1, center); // doesnt work

}

// void	test_hook(void* display)
// {
// 	uint32_t i;
// 	uint32_t j;
// 	uint32_t step;

// 	i = 0;
// 	j = 0;
// 	step = 1;
// 	set_point(display, 1500, 200, 0);

// 	while (i < WIDTH && j < WIDTH)
// 	{
// 		set_point(display, i, j, 1);
// 		draw_update(display);
// 		i+= step;
// 		j+= step;
// 	}
// }