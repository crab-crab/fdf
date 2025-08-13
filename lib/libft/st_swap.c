/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:40:27 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 12:09:35 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.*/
void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*temp_1;
	t_list	*temp_2;

	if (!*stack || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = (*stack)->next;
	(first->previous)->next = second;
	(second->next)->previous = first;
	temp_1 = first->previous;
	temp_2 = second->next;
	second->next = first;
	second->previous = temp_1;
	first->next = temp_2;
	first->previous = second;
	*stack = second;
}
