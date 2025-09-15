#include "fdf.h"



// int32_t	main(void)
// {
// 	t_display	*display;q
	
// 	display = (t_display*)malloc(sizeof(t_display));
// 	display->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!display->mlx)
// 		exit(EXIT_FAILURE);
// 	display->g_img = mlx_new_image(display->mlx, 2000, 2000);
// 	mlx_image_to_window(display->mlx, display->g_img, 0, 0);
// 	mlx_loop_hook(display->mlx, &test_hook, display);
// 	mlx_loop(display->mlx);
// 	mlx_terminate(display->mlx);
// 	return (EXIT_SUCCESS);
// }

int dyn_zoom(t_display	*display)
{
	int hypo;

	hypo = sqrt((display->map->size_x * display->map->size_x) + (display->map->size_y * display->map->size_y));

	return (WIDTH / hypo);
}

void	set_projection(t_display	*display)
{
	display->rx = display->projection.rx;
	display->ry = display->projection.ry;
	display->rz = display->projection.rz;

}

t_display	*init_display(t_map *map)
{
	t_display	*display;
	display = (t_display*)malloc(sizeof(t_display));
	display->mlx = mlx_init(WIDTH, HEIGHT, "Chicken Coop", true);
	display->g_img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
	display->map = map;
	display->zoom_factor = dyn_zoom(display)/2;
	display->offset_x = (WIDTH / 2) - 200;
	display->offset_y = (HEIGHT / 2) - 200;

	return (display);
}

void black_screen(t_display	*display)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(display->g_img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void hook(void *param)
{
	t_display	*display;

	display = param;
	user_input(display);
	black_screen(display);
	draw_grid(display);
}

/*
Add
	-Keyhooks
*/

int main(void)
{
	t_map map;
	t_display	*display;
	int	result;

	char filename[100] = "test_maps/mars.fdf";
	result = parse_map(filename, &map);
	p_map(&map);

	display = init_display(&map);
	display->projection = ISO_PROJ;
	set_projection(display);
	
	if (!display || !display->mlx || !display->g_img)
		exit(EXIT_FAILURE);

	mlx_image_to_window(display->mlx, display->g_img, 0, 0);
	mlx_loop_hook(display->mlx, &hook, display);
	mlx_loop(display->mlx);
	mlx_terminate(display->mlx);
}
