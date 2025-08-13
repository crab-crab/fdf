/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:04:08 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:15:16 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	find_start_end(char const *s1, char const *set, int *trim_measures)
{
	int		i_start;
	int		i_end;
	int		i;
	int		len;

	i = 0;
	while (s1[i] && ft_strchr(set, (int)s1[i]))
		i++;
	i_start = i;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_strchr(set, (int)s1[i]))
		i--;
	i_end = i;
	if (i_end < 0)
		i_end = 0;
	len = i_end - i_start + 1;
	if (len < 0)
		len = 0;
	trim_measures[0] = i_start;
	trim_measures[1] = len;
}

/* Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters
from ’set’ removed from the beginning and the end. Returns trimmed string or NULL
if allocation fails*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		trim_measures[2];
	char	*result;

	if (!*set)
		return (ft_strdup(s1));
	find_start_end(s1, set, trim_measures);
	result = ft_substr(s1, trim_measures[0], trim_measures[1]);
	return (result);
}
