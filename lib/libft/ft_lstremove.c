/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:20:08 by crabin            #+#    #+#             */
/*   Updated: 2025/07/07 17:20:29 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*remove the reference to a member in linked list.
Links elements before and after to each other.
Does not free original struct*/
void	lst_remove(t_list **lst_member)
{
	t_list	*tmp;

	tmp = *lst_member;
	if (tmp->next == tmp)
	{
		*lst_member = NULL;
		return ;
	}
	*lst_member = (*lst_member)->next;
	(tmp->previous)->next = tmp->next;
	(tmp->next)->previous = tmp->previous;
}
