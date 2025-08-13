/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_rerotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:19:18 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 12:09:22 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Shift down all elements of stack a by 1.
The last element becomes the first one*/
void	rerotate(t_list **stack)
{
	*stack = (*stack)->previous;
}
