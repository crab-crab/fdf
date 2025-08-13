/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:45:54 by crabin            #+#    #+#             */
/*   Updated: 2025/06/30 15:04:35 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*the int argument is converted to an
unsigned  char, and the resulting character is written*/
int	pt_char(va_list *args)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*args, int);
	return (write (1, &c, 1));
}
