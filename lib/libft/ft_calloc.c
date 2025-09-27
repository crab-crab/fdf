/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:17:27 by crabin            #+#    #+#             */
/*   Updated: 2025/09/23 18:46:04 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  bzero()  function  erases  the  data in the n bytes of the memory
starting at the location pointed to by s, by writing zeros 
(bytes containing '\0') to that area.*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (ULONG_MAX / nmemb < size || ULONG_MAX / size < nmemb)
		return (NULL);
	total_size = nmemb * size;
	temp = malloc(total_size);
	if (temp)
	{
		ft_bzero(temp, total_size);
		return (temp);
	}
	else
		return (NULL);
}
