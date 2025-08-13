/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:09:29 by crabin            #+#    #+#             */
/*   Updated: 2025/05/09 15:13:39 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  strdup() function returns a pointer to a new string which is a
duplicate of the string s.  Memory for the new string is obtained with
malloc(3), and can be freed with free(3).*/
char	*ft_strdup(const char *s)
{
	int		len;
	char	*tmp;

	len = ft_strlen(s) + 1;
	tmp = (char *)malloc((len) * sizeof(char));
	if (!tmp)
		return (NULL);
	(void)ft_strlcpy(tmp, s, len);
	return (tmp);
}
