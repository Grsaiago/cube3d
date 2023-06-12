/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:49:04 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/19 09:53:27 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	void	*aux;
	t_list	*node;

	if (!lst)
		return ;
	node = *lst;
	while (node)
	{
		aux = node->next;
		if (del)
			del(node->content);
		free(node);
		node = aux;
	}
	*lst = NULL;
	return ;
}
