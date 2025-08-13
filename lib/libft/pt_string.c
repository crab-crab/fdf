/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:46:27 by crabin            #+#    #+#             */
/*   Updated: 2025/06/30 15:04:52 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*the const char * argument is ex‐
pected to be a pointer to an array of character type (pointer to
a string).  Characters from the array are written up to (but not
including) a terminating null byte ('\0');*/
int	pt_string(va_list *args)
{
	const char	*str;

	str = va_arg(*args, const char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
