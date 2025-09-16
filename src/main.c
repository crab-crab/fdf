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

void hook(void *param)
{
	t_display	*display;

	display = param;
	user_input(display);
	wipe_screen(display, 0x606060FF);
	draw_grid(display);
}

/*
Add
	-Keyhooks
*/

int main(int argc, char **argv)
{
	t_map map;
	t_display	*display;
	int	result;

	if (argc != 2)
		return(write(1, "invalid args\n", 13));
	
	//char filename[100] = "test_maps/pylone.fdf";
	//result = parse_map(filename, &map, argv[1]);
	result = parse_map(argv[1], &map); // fit this directly into init_display call?
	p_map(&map);

	display = init_display(&map);
	if (!display)
		exit(EXIT_FAILURE); //check use of exit -> change to return?

	mlx_image_to_window(display->mlx, display->g_img, 0, 0);
	mlx_loop_hook(display->mlx, &hook, display);
	mlx_loop(display->mlx);
	mlx_terminate(display->mlx);
}
