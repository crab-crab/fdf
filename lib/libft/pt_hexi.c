/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_hexi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:02:33 by crabin            #+#    #+#             */
/*   Updated: 2025/06/30 15:04:42 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The unsigned int argument is converted to unsigned hexadecimal (x and X) nota‐
tion.  The letters abcdef are used for x conversions;  the  let‐
ters  ABCDEF are used for X conversions.*/
int	pt_hexi(va_list *args, const char *base_str)
{
	unsigned int	nbr;
	char			result[18];
	size_t			len;

	nbr = va_arg(*args, unsigned int);
	if (nbr == 0)
		return (write(1, "0", 1));
	len = to_hex(base_str, nbr, result);
	write(1, result, len);
	return (len);
}
