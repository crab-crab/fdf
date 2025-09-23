/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:34:48 by crabin            #+#    #+#             */
/*   Updated: 2025/09/23 17:10:15 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory (using malloc(3)) and returns a new string, which is the
result of concatenating ’s1’ and ’s2’. Return NULL if malloc fails*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	(void)ft_strlcpy(new_str, s1, (s1_len + s2_len + 1));
	(void)ft_strlcat(new_str + s1_len, s2, s2_len + 1);
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}
