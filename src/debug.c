/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:18:04 by crabin            #+#    #+#             */
/*   Updated: 2025/09/17 15:07:12 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void p_display_val(t_display	*display)
{
	printf("Display Values: \n");
	printf("p0 | x:%d y:%d\n", display->p0.pix_x, display->p0.pix_y);
	printf("p1 | x:%d y:%d\n", display->p1.pix_x, display->p1.pix_y);
}

void p_point(t_point *p)
{
	printf("Point | x:%f y:%f z:%f | pi_x:%d pi_y:%d \n", p->x, p->y, p->z, p->pix_x, p->pix_y);
}

void p_map(t_map *map)
{
	uint32_t i = 0;
	uint32_t j;
	
	if (!map)
	{
		printf("NULL map\n");
		return;
	}
	
	printf("Map | X: %d | Y: %d\n", map->size_x, map->size_y);
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			printf("%d,%d ", map->node_arr[i][j].z, map->node_arr[i][j].colour);
			j++;
		}
		printf("\n");
		i++;
	}
}

void p_colour(uint32_t c)
{
	t_colour colour;
	
	get_rgb(c, &colour);
	printf("Colour %u | R%d G%d B%d\n", c, colour.rr, colour.gg, colour.bb);
}
