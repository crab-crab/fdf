/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:21:45 by crabin            #+#    #+#             */
/*   Updated: 2025/09/01 12:35:46 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strlcpy() function copies up to size - 1 characters from the NUL-
terminated string src to dst, NUL-terminating the result.

The strlcpy() function returns the total length of the string
it tried to create.  For strlcpy() that means the length of src.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	src_len;
	int		i;

	src_len = ft_strlen(src);
	i = 0;
	if (!src || src_len == 0)
		return (src_len);
	while (src[i] && dsize > 1)
	{
		dst[i] = src[i];
		i++;
		dsize --;
	}
	if (dsize > 0)
		dst[i] = '\0';
	return (src_len);
}
