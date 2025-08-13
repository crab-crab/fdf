/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:08:07 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:11:31 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  memchr()  function  scans the initial n bytes of the memory area
pointed to by s for the first instance of c.  Both c and the bytes of the
memory area pointed to by s are interpreted as unsigned char. 

The  memchr() function return a pointer to the matching byte or NULL if the
character does not occur in the given memory area.*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n > 0)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
