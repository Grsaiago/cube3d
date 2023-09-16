/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:20:17 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/19 09:51:39 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !del || !(f))
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	first_node = lst;
	while (lst)
	{
		new_node = ft_lstnew((f)(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	lst = first_node;
	return (new_lst);
}
