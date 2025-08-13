/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:27:58 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:14:52 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the function f to each character of the string s, passing its index
as the first argument and the character itself as the second. A new string is
created (using malloc(3)) to store the results from the successive applications
of f. */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*new;
	int		i;

	i = 0;
	len = ft_strlen(s);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
