/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:51:46 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 11:40:06 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of nodes in the list*/
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*start;

	start = lst;
	size = 0;
	while (lst->next != start)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
