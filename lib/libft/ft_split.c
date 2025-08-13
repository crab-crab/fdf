/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:50:25 by crabin            #+#    #+#             */
/*   Updated: 2025/05/10 16:01:26 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_sections(char const *s, char c)
{
	int		count;
	char	prev;

	count = 0;
	prev = c;
	while (*s)
	{
		if (prev == c && *s != c)
			count++;
		prev = *s;
		s++;
	}
	return (count);
}

static void	sub_index(char const *s, char c, int *slice)
{
	char	prev;
	int		i;

	prev = c;
	i = 0;
	slice[0] = 0;
	while (s[i])
	{
		if (prev == c && s[i] != c)
			slice[0] = i;
		if (prev != c && s[i] == c)
		{
			slice[1] = i;
			return ;
		}
		prev = s[i];
		i++;
	}
	slice[1] = i;
}

static void	delete(char **array, int i)
{
	while (i >= 0)
	{
		if (array[i])
			free(array[i]);
		i--;
	}
	if (array)
		free(array);
}

/*Allocates memory (using malloc(3)) and returns an array of strings obtained
by splitting ’s’ using the character ’c’ as a delimiter. The array must
end with a NULL pointer.*/
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**sections;
	int		slice[2];

	j = 0;
	i = 0;
	sections = (char **)malloc((count_sections(s, c) + 1) * sizeof(char *));
	if (!sections || !s)
		return (NULL);
	while (s[i] && j < count_sections(s, c))
	{
		sub_index(s + i, c, slice);
		sections[j] = ft_substr(&s[i], slice[0], (slice[1] - slice[0]));
		if (!sections[j])
		{
			delete(sections, j);
			return (NULL);
		}
		i += slice[1];
		j++;
	}
	sections[j] = NULL;
	return (sections);
}
