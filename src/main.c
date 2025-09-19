#include "fdf.h"



void hook(void *param)
{
	t_display	*display;

	display = param;
	user_input(display);
	wipe_screen(display, 0x606060FF);
	draw_grid(display);
}

void cleanup(t_display	*display)
{
	free(display->map->nodes);
	free(display->map);

	mlx_terminate(display->mlx);


	free(display);
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
	cleanup(display);
}
