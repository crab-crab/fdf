/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:47:28 by crabin            #+#    #+#             */
/*   Updated: 2025/06/30 14:59:33 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_numlen(unsigned int n)
{
	unsigned int	num;
	unsigned int	len;

	len = 0;
	num = n;
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len + 1);
}

static unsigned int	ft_power(unsigned int num, int exponent)
{
	unsigned int	multi;

	if (num == 0)
		return (0);
	if (exponent <= 0)
		return (1);
	multi = num;
	while (exponent > 1)
	{
		num *= multi;
		exponent--;
	}
	return (num);
}

/*Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled*/
char	*ft_uitoa(unsigned int n, char *result)
{
	unsigned int		num_len;
	unsigned int		i;
	unsigned int		num;

	num = n;
	i = 0;
	num_len = ft_numlen(num);
	while (i < num_len)
	{
		result[i] = (num / ft_power(10, num_len - (i + 1))) + '0';
		num = num % ft_power(10, (num_len - (i + 1)));
		i++;
	}
	result[i] = '\0';
	return (result);
}
