#include "fdf.h"

void p_display_val(t_display	*display)
{
	printf("Display Values: \n");
	printf("p0 | x:%d y:%d\n", display->p0.pix_x, display->p0.pix_y);
	printf("p1 | x:%d y:%d\n", display->p1.pix_x, display->p1.pix_y);
}

void p_map(t_map map)
{
	uint32_t i = 0;
	uint32_t j;
	
	printf("Map | X: %d | Y: %d\n", map.size_x, map.size_y);
	while (i < map.size_y)
	{
		j = 0;
		while (j < map.size_x)
		{
			printf("%d,%d ", map.node_arr[i][j].z, map.node_arr[i][j].colour);
			j++;
		}
		printf("\n");
		i++;
	}
}

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
	p_map(map);
	display = (t_display*)malloc(sizeof(t_display));
	display->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	display->map = &map;
	if (!display->mlx)
		exit(EXIT_FAILURE);
	display->g_img = mlx_new_image(display->mlx, 2000, 2000);
	mlx_image_to_window(display->mlx, display->g_img, 0, 0);
	mlx_loop_hook(display->mlx, &grid_hook, display);
	mlx_loop(display->mlx);
	mlx_terminate(display->mlx);
}