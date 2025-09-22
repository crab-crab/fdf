/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:18:04 by crabin            #+#    #+#             */
/*   Updated: 2025/09/22 17:25:01 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void p_display_val(t_display	*display)
{
	printf("Display Values: \n");
	printf("p0 | x:%f y:%f\n", display->p0->pix_x, display->p0->pix_y);
	printf("p1 | x:%f y:%f\n", display->p1->pix_x, display->p1->pix_y);
}

void p_map(t_map *map)
{
	int32_t i = 0;
	int32_t j;
	uint32_t index;
	
	if (!map)
	{
		printf("NULL map\n");
		return;
	}
	
	printf("Map | X: %d | Y: %d\n", map->size_x, map->size_y);
	return ;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			index = i * map->size_x + j;
			printf("|%d,%d,%d,%d| \t ", map->nodes[index].x_orig, map->nodes[index].y_orig, map->nodes[index].z_orig, map->nodes[index].colour);
			j++;
		}
		printf("\n");
		i++;
	}
}

