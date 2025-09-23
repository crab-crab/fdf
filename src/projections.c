/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:58:07 by crabin            #+#    #+#             */
/*   Updated: 2025/09/23 16:27:57 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// the one we all know and love, 120 deg between all 3 axis
// 0.523599 radians = 30 deg
void	isometric_n(t_node *node)
{
	node->pix_x = ((node->x - node->y) * cos(0.523599));
	node->pix_y = ((node->x + node->y) * sin(0.523599) - node->z);
}

// topdown
void	topdown(t_node *node)
{
	node->pix_x = node->x;
	node->pix_y = node->y;
}

// like isometric but instead of treating all axes equally,
// two axes share same angle while third is different
void	dimetric_n(t_node *node)
{
	node->pix_x = node->x * cosf(0.785398) + node->y * cosf(0.61548);
	node->pix_y = node->x * sinf(0.785398) - node->y * sinf(0.61548) - node->z;
}

// x–y plane unchanged, z slanted backward 45°
void	cabinet_n(t_node *node)
{
	float	scale;

	scale = 0.5;
	node->pix_x = node->x + node->z * scale * cosf(0.785398);
	node->pix_y = node->y + node->z * scale * sinf(0.785398);
}

/*
Takes node typedef and updates spatial and render coordinates
add casting for funky render option?
*/
void	resolve_node(t_display *display, t_node *node)
{
	node->x = node->x_orig;
	node->y = node->y_orig;
	node->z = node->z_orig * display->height_scale;
	rotate_node(node, display);
	if (display->proj == ISOMETRIC)
		isometric_n(node);
	else if (display->proj == TOPDOWN)
		topdown(node);
	else if (display->proj == DIMETRIC)
		dimetric_n(node);
	else if (display->proj == CABINET)
		cabinet_n(node);
	node->pix_x = ((display->offset_x) + (node->pix_x * display->zoom_factor));
	node->pix_y = ((display->offset_y) + (node->pix_y * display->zoom_factor));
}
