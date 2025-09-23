/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:21:19 by crabin            #+#    #+#             */
/*   Updated: 2025/09/23 16:21:56 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x_n(t_node *node, float cos_t, float sin_t)
{
	float	y;
	float	z;

	y = node->y;
	z = node->z;
	node->y = (y * cos_t) - (z * sin_t);
	node->z = (y * sin_t) + (z * cos_t);
}

void	rotate_y_n(t_node *node, float cos_t, float sin_t)
{
	float	x;
	float	z;

	x = node->x;
	z = node->z;
	node->x = (x * cos_t) + (z * sin_t);
	node->z = (-x * sin_t) + (z * cos_t);
}

void	rotate_z_n(t_node *node, float cos_t, float sin_t)
{
	float	x;
	float	y;

	x = node->x;
	y = node->y;
	node->x = (x * cos_t) - (y * sin_t);
	node->y = (x * sin_t) + (y * cos_t);
}

void	rotate_node(t_node *node, t_display *display)
{
	rotate_x_n(node, display->cos_rx, display->sin_rx);
	rotate_y_n(node, display->cos_ry, display->sin_ry);
	rotate_z_n(node, display->cos_rz, display->sin_rz);
}
