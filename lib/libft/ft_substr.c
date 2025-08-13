/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:42:40 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:15:20 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory (using malloc(3)) and returns a substring from the string
’s’. The substring starts at index ’start’ and has a maximum length of ’len’ */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	(void)ft_strlcpy(tmp, (s + start), len + 1);
	return (tmp);
}
