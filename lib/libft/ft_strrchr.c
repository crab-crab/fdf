/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:48:24 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:15:02 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "stdio.h"

/* The strrchr() function returns a pointer to the matched character or NULL if
the character is not  found. The terminating  null byte is considered part of 
the string, so that if c is specified as '\0', these functions return a pointer
to the terminator.*/
char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*last;

	tmp = (char *)s;
	last = NULL;
	while (*tmp)
	{
		if (*tmp == (unsigned char)c)
			last = tmp;
		tmp++;
	}
	if (*tmp == (unsigned char)c)
		last = tmp;
	return (last);
}
