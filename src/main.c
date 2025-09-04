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

int main(void)
{
	t_map map;
	t_display	*display;
	int	result;

	char filename[100] = "test_maps/elem-col.fdf";
	result = parse_map(filename, &map);
	p_map(&map);
	display = (t_display*)malloc(sizeof(t_display));
	display->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	display->g_img = mlx_new_image(display->mlx, 2000, 2000);
	display->map = &map;
	display->zoom_factor = 70;
	display->offset_x = 100;
	display->offset_y = 100;
	// p_map(&map);
	// return(1);
	if (!display->mlx || !display->g_img)
		exit(EXIT_FAILURE);
	mlx_image_to_window(display->mlx, display->g_img, 0, 0);
	mlx_loop_hook(display->mlx, &grid_hook, display);
	mlx_loop(display->mlx);
	mlx_terminate(display->mlx);
}