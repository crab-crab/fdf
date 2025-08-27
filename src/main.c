#include "fdf.h"

#define WIDTH 2000
#define HEIGHT 2000

void	hook(void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_P))
		mlx_delete_image(mlx, g_img);

	// Octave 1
	draw_line(0, 200, 500, 500);
	draw_line(0, 100, 500, 500); //YES
	// Octave 2
	draw_line(200, 0, 500, 500);
	draw_line(100, 0, 500, 500); //YES

	// Octave 3
	draw_line(100, 1000, 500, 500); //YES
	draw_line(200, 1000, 500, 500);
	// Octave 4
	draw_line(0, 900, 500, 500); //YES
	draw_line(0, 800, 500, 500);

	// Octave 5
	draw_line(500, 500, 1000, 900); //YES
	draw_line(500, 500, 1000, 800);
	// Octave 6
	draw_line(500, 500, 900, 1000); //YES
	draw_line(500, 500, 800, 1000);

	// Octave 7
	draw_line(500, 500, 900, 0); //YES
	draw_line(500, 500, 800, 0); 
	// Octave 8
	draw_line(500, 500, 1000, 100); //YES
	draw_line(500, 500, 1000, 200);

	//crosshair
	draw_line(500, 0, 500, 500); // vertical top
	draw_line(0, 500, 500, 500); // horizontal left
	draw_line(500, 500, 500, 1000); // horizontal right
	draw_line(500, 500, 1000, 500); // vertical bottom

}



int32_t	main(void)
{
	t_display	*display;
	
	display->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!display->mlx)
		exit(EXIT_FAILURE);
	display->g_img = mlx_new_image(display->mlx, 2000, 2000);
	mlx_image_to_window(display->mlx, display->g_img, 0, 0);
	mlx_loop_hook(display->mlx, &hook, display->mlx);
	mlx_loop(display->mlx);
	mlx_terminate(display->mlx);
	return (EXIT_SUCCESS);
}