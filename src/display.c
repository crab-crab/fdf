#include "fdf.h"

void	set_projection(t_display	*display)
{
	display->rx = display->projection.rx;
	display->ry = display->projection.ry;
	display->rz = display->projection.rz;

}

void wipe_screen(t_display	*display, uint32_t colour)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(display->g_img, x, y, colour);
			x++;
		}
		y++;
	}
}

/*
Check into MLX42 specific cleanup functions 
mlx_terminate() mlx_delete_image()
*/
void free_display(t_display	**display_p)
{
	t_display *display = *display_p;
	
	if (!display_p || !*display_p)
        return;
	
	if (display->g_img)
	{
		free(display->g_img);
		display->g_img = NULL;
	}

	if (display->mlx)
	{
		free(display->mlx);
		display->mlx = NULL;
	}
	
	free(display);
	*display_p = NULL;
}

int dyn_zoom(t_display	*display)
{
	int hypo;

	hypo = sqrt((display->map->size_x * display->map->size_x) + (display->map->size_y * display->map->size_y));

	return (WIDTH / hypo);
}

void reset_display(t_display	*display)
{
	display->node = -1;
	display->node_fill = 1;
	display->node_rad = NODE_RADIUS;
	display->zoom_factor = dyn_zoom(display)/2;
	display->offset_x = (WIDTH / 2) - 200;
	display->offset_y = (HEIGHT / 2) - 200;
	display->projection = TOPDOWN;
	display->height_scale = HEIGHT_SCALE;
	set_projection(display);
}


t_display	*init_display(t_map *map)
{
	t_display	*display;

	display = (t_display*)ft_calloc(1, sizeof(t_display));
	if (!display || !map)
		return (NULL);
	display->mlx = mlx_init(WIDTH, HEIGHT, "Chicken Coop", true);
	if (!display->mlx)
		return (free_display(&display), NULL);
	display->g_img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
	if (!display->g_img)
		return (free_display(&display), NULL);
	display->map = map;
	reset_display(display); //test

	set_projection(display);

	return (display);
}
