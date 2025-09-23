/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:18:58 by crabin            #+#    #+#             */
/*   Updated: 2025/09/23 16:41:51 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook(void *param)
{
	t_display	*display;

	display = param;
	user_input(display);
	wipe_screen(display, 0x606060FF);
	draw_grid(display);
}

void	cleanup(t_display	*display)
{
	free(display->map->nodes);
	free(display->map);
	mlx_terminate(display->mlx);
	free(display);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_display	*display;
	int			result;

	if (argc != 2)
		return (write(1, "invalid args\n", 13));
	result = parse_map(argv[1], &map);
	display = init_display(&map);
	if (!display)
		return (EXIT_FAILURE);
	mlx_image_to_window(display->mlx, display->g_img, 0, 0);
	mlx_loop_hook(display->mlx, &hook, display);
	mlx_loop(display->mlx);
	cleanup(display);
	return (1);
}
