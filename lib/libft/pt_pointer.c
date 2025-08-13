/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:46:51 by crabin            #+#    #+#             */
/*   Updated: 2025/06/30 15:04:49 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The void * pointer argument is printed in hexadecimal*/
int	pt_pointer(va_list *args)
{
	unsigned long	n_ptr;
	char			result[18];
	int				hex_len;

	n_ptr = (unsigned long)va_arg(*args, void *);
	if (!n_ptr)
		return (write(1, "(nil)", 5));
	hex_len = to_hex(HEX_LOWER, n_ptr, result);
	return (write(1, "0x", 2) + write(1, result, hex_len));
}
