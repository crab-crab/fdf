/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:18:25 by crabin            #+#    #+#             */
/*   Updated: 2025/09/18 14:45:00 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t ft_abs(int32_t num)
{
	if (num == INT32_MIN)
		return (INT32_MAX);
	if (num < 0)
		num = -num;
	return (num);
}

float dtor(float degrees)
{
	return ((degrees * PI) / 180);
}

float rtod(float radians)
{
	return (radians * (180 / PI));
}
