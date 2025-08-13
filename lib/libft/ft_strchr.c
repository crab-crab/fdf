/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:39:18 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:12:28 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strchr() function returns a pointer to the first occurrence of the
character c in the string s. 

The strchr() function returns a pointer to the matched character or NULL if
the character is not found. The terminating null byte is considered part of
the string, so that if c is specified as '\0', these functions return a pointer
to the terminator.*/
char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
	}
	if (*tmp == (unsigned char)c)
		return (tmp);
	else
		return (NULL);
}
