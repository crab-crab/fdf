/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:36:46 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:17:13 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strlcat() function appends the NUL-terminated string src to the end of-
dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the 
result.

Returns total length of the string it tried to create, that means the initial
length of dst plus the length of src.*/
size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t			src_len;
	size_t			dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (dest_len >= dsize)
		dest_len = dsize;
	if (dest_len == dsize)
		return (src_len + dest_len);
	if (dsize > src_len + dest_len)
		ft_memcpy(dst + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dest_len, src, dsize - dest_len - 1);
		dst[dsize - 1] = 0;
	}
	return (src_len + dest_len);
}

/*If strlcat() traverses size characters without finding a NUL, the length of
the string is considered to be size and the destination string will not be 
NUL-terminated (since there was no space for the NUL).  
This keeps strlcat() from running off the end of a string.*/
