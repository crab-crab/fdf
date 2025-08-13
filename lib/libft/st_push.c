/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:58:27 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 12:10:03 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Take the first element at the top of stack 1 and put it at the top of stack 2.
Do nothing if first stack is empty.*/
void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *stack_1;
	if ((*stack_1)->next != *stack_1)
		new = (*stack_1)->next;
	else
		new = NULL;
	if (!*stack_1)
		return ;
	lst_remove(stack_1);
	if (!(*stack_2))
		*stack_2 = ft_lstcreate(tmp);
	else
		ft_lstadd_front(stack_2, tmp);
	*stack_1 = new;
}
