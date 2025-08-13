/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:40:50 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:14:59 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strnstr() function locates the first occurrence of the null-terminated
string little in the string big, where not more than len characters are
searched.  Characters that appear after a ‘\0’ character are not searched.*/
char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*small)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] == small[j] && small[j] && i + j < len)
		{
			j++;
		}
		if (small[j] == '\0')
			return ((char *)(big + i));
		j = 0;
		i++;
	}
	return (NULL);
}
