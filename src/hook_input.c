/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:12:52 by crabin            #+#    #+#             */
/*   Updated: 2025/09/16 16:15:04 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void rot_input(t_display	*display)
{
	if (mlx_is_key_down(display->mlx, MLX_KEY_W))
		display->rx += ROT_STEP;
	if else(mlx_is_key_down(display->mlx, MLX_KEY_S))
		display->rx -= ROT_STEP;
	if else(mlx_is_key_down(display->mlx, MLX_KEY_A))
		display->ry += ROT_STEP;
	if else(mlx_is_key_down(display->mlx, MLX_KEY_D))
		display->ry -= ROT_STEP;
	if else(mlx_is_key_down(display->mlx, MLX_KEY_Q))
		display->rz += ROT_STEP;
	if else(mlx_is_key_down(display->mlx, MLX_KEY_E))
		display->rz -= ROT_STEP;
	if else(mlx_is_key_down(display->mlx, MLX_KEY_SPACE))
		reset_display(display);
}

void nodes_input(t_display	*display)
{
	if (mlx_is_key_down(display->mlx, MLX_KEY_SEMICOLON))
		display->node_fill *= -1;
	if (mlx_is_key_down(display->mlx, MLX_KEY_P))
		display->node *= -1;
	if (mlx_is_key_down(display->mlx, MLX_KEY_O))
	{
		if (display->node_rad > 0)
			display->node_rad--;
	}
	if (mlx_is_key_down(display->mlx, MLX_KEY_L))
	{
		if (display->node_rad < WIDTH / 3)
			display->node_rad++;
	}
}

void trans_input(t_display	*display)
{
	if (mlx_is_key_down(display->mlx, MLX_KEY_RIGHT))
		display->offset_x += TRAN_STEP;
	if (mlx_is_key_down(display->mlx, MLX_KEY_LEFT))
		display->offset_x -= TRAN_STEP;
	if (mlx_is_key_down(display->mlx, MLX_KEY_DOWN))
		display->offset_y += TRAN_STEP;
	if (mlx_is_key_down(display->mlx, MLX_KEY_UP))
		display->offset_y -= TRAN_STEP;
	if (mlx_is_key_down(display->mlx, MLX_KEY_Z))
		display->zoom_factor *= ZOOM_STEP;
	if (mlx_is_key_down(display->mlx, MLX_KEY_X))
		display->zoom_factor /= ZOOM_STEP;
}

void user_input(t_display	*display)
{
	if (mlx_is_key_down(display->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(display->mlx);

	rot_input(display);
	nodes_input(display);
	trans_input(display);
}