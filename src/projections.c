/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:58:07 by crabin            #+#    #+#             */
/*   Updated: 2025/09/17 15:19:30 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric_n(t_node *node, int32_t *x_pix, int32_t *y_pix)
{
	node->pix_x = ((node->x - node->y) * cos(0.523599));
	node->pix_y = ((node->x + node->y) * sin(0.523599) - node->z);
}

void reset_node(t_node *node)
{
	node->x = node->x_orig;
	node->y = node->y_orig;
	node->z = node->z_orig * display->height_scale;
}


void resolve_node(t_display *display, t_node *node)
{
	
	node->x = node->x_orig;
	node->y = node->y_orig;
	node->z = node->z_orig * display->height_scale;
	rotate_node(node, display->rx, display->ry, display->rz);
	isometric_n(node);

	node->pix_x = (int32_t)((display->offset_x) + (node->pix_x * display->zoom_factor));
	node->pix_y = (int32_t)((display->offset_y) + (node->pix_y * display->zoom_factor));
}