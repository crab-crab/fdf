/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:45:00 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 11:39:15 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print(t_list *lst)
{
	t_list	*head;

	head = lst;
	if (!lst)
		return ;
	while (lst->next != head)
	{
		ft_printf("%d ", lst->content);
		lst = lst->next;
	}
	ft_printf("%d", lst->content);
}

void	ft_lst_lenprint(t_list *lst, int size)
{
	t_list	*head;

	head = lst;
	if (!lst)
		return ;
	while (lst->next != head && size > 0)
	{
		ft_printf("%d ", lst->content);
		lst = lst->next;
		size--;
	}
	ft_printf("%d", lst->content);
}
