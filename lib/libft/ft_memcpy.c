/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:36:52 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:11:36 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  memcpy()  function  copies  n bytes from memory area src to memory area
dest.  The memory areas must not overlap. The memcpy() function returns a 
pointer to dest.*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	while (n > 0)
	{
		*dest_tmp = *src_tmp;
		dest_tmp++;
		src_tmp++;
		n--;
	}
	return (dest);
}
