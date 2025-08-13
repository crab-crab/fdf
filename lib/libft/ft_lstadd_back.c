/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:52:17 by crabin            #+#    #+#             */
/*   Updated: 2025/07/07 17:44:03 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the node ’new’ at the end of the list*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	(*lst)->previous->next = new;
	new->previous = (*lst)->previous;
	(*lst)->previous = new;
	new->next = *lst;
}
