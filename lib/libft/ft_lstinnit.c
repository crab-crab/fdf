/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinnit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crabin <crabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:42:59 by crabin            #+#    #+#             */
/*   Updated: 2025/07/15 11:39:41 by crabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstinnit(int content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return (NULL);
	new->next = new;
	new->previous = new;
	return (new);
}

t_list	*ft_lstcreate(t_list	*new)
{
	new->next = new;
	new->previous = new;
	return (new);
}
