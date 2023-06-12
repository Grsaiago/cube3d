/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:35:00 by gsaiago           #+#    #+#             */
/*   Updated: 2022/12/18 13:35:00 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_if(t_list **head, void *data, int (*f)())
{
	t_list	*node;

	if (!head || !*head)
		return ;
	node = *head;
	if (!f(data, node->next))
	{
		*head = node->next;
		free(node);
		ft_lst_remove_if(head, data, f);
	}
	node = *head;
	ft_lst_remove_if(&node->next, data, f);
	return ;
}
