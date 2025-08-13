/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:51:07 by crabin            #+#    #+#             */
/*   Updated: 2025/07/07 17:24:53 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Adds the node ’new’ at the beginning of the list*/
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!new || !alst)
		return ;
	last = (*alst)->previous;
	new->previous = last;
	new->next = *alst;
	last->next = new;
	(*alst)->previous = new;
	*alst = new;
}
