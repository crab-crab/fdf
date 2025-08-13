/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:53:15 by crabin            #+#    #+#             */
/*   Updated: 2025/06/30 15:05:49 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	check_power_of(unsigned long nbr, unsigned long divisor)
{
	unsigned long	divide_count;

	divide_count = 0;
	if (!nbr)
		return (0);
	while (nbr >= divisor)
	{
		nbr /= divisor;
		divide_count++;
	}
	return (divide_count);
}

static unsigned long	ft_power(unsigned long num, int pow)
{
	unsigned long	multiplier;

	multiplier = num;
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	while (pow > 1)
	{
		num = num * multiplier;
		pow--;
	}
	return (num);
}

int	to_hex(const char *base_str, unsigned long input, char *result)
{
	unsigned long	index;
	unsigned long	ch_pow;
	unsigned long	base_power;

	index = 0;
	ch_pow = check_power_of(input, 16);
	while (index <= ch_pow)
	{
		base_power = ft_power(16, (ch_pow - index));
		result[index] = base_str[input / base_power];
		input -= base_power * (input / base_power);
		index++;
	}
	result[index] = '\0';
	return (index);
}
