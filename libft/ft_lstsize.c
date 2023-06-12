/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:26:43 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/19 09:51:07 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	node = lst;
	while (node->next)
	{
		i++;
		node = node->next;
	}
	return (i);
}
/*
int main(void)
{
	t_list	*fnode;
	t_list	*node;
	int		i;

	fnode = ft_lstnew(NULL);
	node = ft_lstnew(NULL); 
	ft_lstadd_front(&fnode, node);
	i = ft_lstsize(fnode);
	printf("tamanho da lista é > |%d|\n", i);
}
*/
