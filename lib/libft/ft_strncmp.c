/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:56:52 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:14:56 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strncmp() function compares the first n bytes of the two strings s1 and
s2.  The locale is not taken into account (for a locale-aware comparison, see 
strcoll(3)). The comparison is done using unsigned characters.*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && (unsigned char)*s1 == (unsigned char)*s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
