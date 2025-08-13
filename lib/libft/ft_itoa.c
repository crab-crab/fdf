/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:56:34 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 11:38:24 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	long	num;
	int		len;

	len = 0;
	num = (long)n;
	if (num < 0)
	{
		num *= -1;
	}
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len + 1);
}

static int	ft_power(int num, int exponent)
{
	int	multi;

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

static void	check_negative(long *num, int *negative_bool)
{
	if (*num < 0)
	{
		*negative_bool = 1;
		*num *= -1;
	}
}

static	void	update_negative(char **result, int *result_index,\
		int *negative_bool)
{
	if (*negative_bool == 1)
	{
		*result[0] = '-';
		(*result_index)++;
	}
}

/*Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled*/
char	*ft_itoa(int n)
{
	int		num_len;
	char	*result;
	int		negative_bool;
	int		i;
	long	num;

	num = (long)n;
	i = 0;
	negative_bool = 0;
	check_negative(&num, &negative_bool);
	num_len = ft_numlen(num);
	result = (char *)malloc((num_len + 1 + negative_bool) * sizeof(char));
	if (!result)
		return (NULL);
	update_negative(&result, &i, &negative_bool);
	while (i < num_len + negative_bool)
	{
		num_len = num_len - (i + 1 - negative_bool);
		result[i] = (num / ft_power(10, num_len)) + '0';
		num = num % ft_power(10, num_len);
		i++;
	}
	result[i] = '\0';
	return (result);
}
