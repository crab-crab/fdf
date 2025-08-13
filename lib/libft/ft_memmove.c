/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:46:20 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:13:36 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*copies n bytes from memory area src to memory area dest.  The memory areas
may overlap: copying takes place as though the  bytes in src are first copied
into a temporary array that does not overlap src or dest, and the bytes are
then copied from  the  temporary array to dest*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	if (src_tmp > dest_tmp)
		return (ft_memcpy(dest_tmp, src_tmp, n));
	else
	{
		while (n > 0)
		{
			dest_tmp[n - 1] = src_tmp[n - 1];
			n--;
		}
		return (dest);
	}
}
