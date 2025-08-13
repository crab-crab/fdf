/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:17:07 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 12:09:29 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Shift up all elements of stack a by 1.
The second element becomes the first one*/
void	rotate(t_list **stack)
{
	*stack = (*stack)->next;
}
