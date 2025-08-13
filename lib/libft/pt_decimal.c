/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:01:44 by crabin            #+#    #+#             */
/*   Updated: 2025/06/30 15:04:38 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  int  argument is converted to signed decimal notation.*/
int	pt_decimal(va_list *args)
{
	long	nbr;
	char	result[21];

	nbr = va_arg(*args, int);
	ft_sitoa(nbr, result);
	return (write(1, result, ft_strlen(result)));
}
