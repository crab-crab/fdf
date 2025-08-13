/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_udecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:02:11 by crabin            #+#    #+#             */
/*   Updated: 2025/06/30 15:04:56 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// /*The unsigned int argument is converted to unsigned  decimal  (u)*/
int	pt_udecimal(va_list *args)
{
	long	nbr;
	char	result[21];

	nbr = va_arg(*args, unsigned int);
	ft_uitoa(nbr, result);
	return (write(1, result, ft_strlen(result)));
}
