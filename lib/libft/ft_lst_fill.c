/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:49:43 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 11:38:41 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_fill(int *arr, size_t size)
{
	t_list	*head;
	size_t	i;

	i = 0;
	if (size < 1)
		return (NULL);
	head = ft_lstinnit(arr[0]);
	if (!head)
		return (NULL);
	while (i++ < size - 1)
	{
		ft_lstadd_back(&head, ft_lstnew(arr[i]));
	}
	return (head);
}
