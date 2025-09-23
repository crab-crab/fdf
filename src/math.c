/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:18:25 by crabin            #+#    #+#             */
/*   Updated: 2025/09/23 16:37:00 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	ft_abs(int32_t num)
{
	if (num == INT32_MIN)
		return (INT32_MAX);
	if (num < 0)
		num = -num;
	return (num);
}

uint8_t	clampf_u8(float value)
{
	if (value < 0)
		return (0);
	else if (value > 255)
		return (255);
	else
		return ((uint8_t)(value + 0.5));
}

float	dtor(float degrees)
{
	return ((degrees * PI) / 180);
}

float	rtod(float radians)
{
	return (radians * (180 / PI));
}
