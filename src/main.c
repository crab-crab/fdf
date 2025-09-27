/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:18:58 by crabin            #+#    #+#             */
/*   Updated: 2025/09/25 15:25:13 by crabin           ###   ########.fr       */
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
	mlx_terminate(display->mlx);
	free(display);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_display	*display;

	if (argc != 2)
		return (write(1, "invalid args\n", 13), EXIT_FAILURE);
	if (parse_map(argv[1], &map) < 1)
		return (write(1, "parse error\n", 12), EXIT_FAILURE);
	if (map.size_x < 2 || map.size_y < 2)
		return (free(map.nodes), write(1, "invalid map\n", 12), EXIT_FAILURE);
	display = init_display(&map);
	if (!display)
		return (free(map.nodes), EXIT_FAILURE);
	mlx_image_to_window(display->mlx, display->g_img, 0, 0);
	mlx_loop_hook(display->mlx, &hook, display);
	mlx_loop(display->mlx);
	cleanup(display);
	return (1);
}
