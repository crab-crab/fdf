/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:28:10 by crabin            #+#    #+#             */
/*   Updated: 2025/06/30 15:04:09 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conv_flag(char c, va_list *args)
{
	if (c == 'c')
		return (pt_char(args));
	else if (c == 's')
		return (pt_string(args));
	else if (c == 'p')
		return (pt_pointer(args));
	else if (c == 'd' || c == 'i')
		return (pt_decimal(args));
	else if (c == 'u')
		return (pt_udecimal(args));
	else if (c == 'x')
		return (pt_hexi(args, HEX_LOWER));
	else if (c == 'X')
		return (pt_hexi(args, HEX_UPPER));
	else if (c == '%')
		return (pt_percent());
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += conv_flag(*format, &args);
		}
		else
		{
			write (1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
