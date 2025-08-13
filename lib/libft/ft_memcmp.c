/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:25:33 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:11:33 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  memcmp() function compares the first n bytes (each interpreted as 
unsigned char) of the memory areas s1 and s2. 

Function returns an integer less than, equal to, or greater than zero if the 
first n bytes of s1 is found, respectively, to be less than, to match, or be
greater than the first n bytes of s2.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*str1 == *str2 && n > 1)
	{
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}
