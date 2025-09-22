/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:24:30 by crabin            #+#    #+#             */
/*   Updated: 2025/09/22 15:24:38 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

char	*ft_strlchr(char *s, int c, size_t l)
{
	if (!s)
		return (NULL);
	while (l > 0 && *s)
	{
		if (*s == (unsigned char)c)
		{
			return (s);
		}
		s++;
		l--;
	}
	return (NULL);
}

/*hextoi()  converts the  portion of the string after 'x' character pointed to by
nptr to int. Returns the converted value or 0 on error/overflow.*/
uint32_t	ft_hextoi(const char *nptr) //move to lib_ft?
{
	uint64_t	result;

	result = 0;
	if (!nptr)
		return (0);
	while (*nptr != 'x' && *nptr)
		nptr++;
	if (!*nptr)
		return (0);
	nptr++;
	while (ft_isdigit(*nptr) || ft_isalpha(*nptr))
	{
		result *= 16;
		if (ft_isdigit(*nptr))
			result += *nptr - '0';
		else if (*nptr >= 'A' && *nptr <= 'F')
			result += (*nptr - 'A') + 10;
		else if (*nptr >= 'a' && *nptr <= 'f')
			result += (*nptr - 'a') + 10;
		nptr++;
	}
	if (result > UINT32_MAX)
		return (0);
	return ((uint32_t)result);
}

int32_t 	ft_size(char **arr)
{
	int32_t size;

	size = 0;
	if (!arr)
		return (-1);
	while (*arr)
	{
		size++;
		arr++;
	}
	return (size);
}

int32_t		count_cells(char *txt, char c)
{
	char	prev;
	int		i;

	i = 0;
	prev = c;
	while (*txt)
	{
		if (ft_isalnum(*txt) && prev == c)
		{
			i++;
		}
		prev = *txt;
		txt++;
	}
	return (i);
}