/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:10:18 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/12 19:15:39 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	**ft_lst_to_mat(t_list *node)
{
	char	**mat;
	int		i;
	int		listsize;

	if (!node)
		return (NULL);
	listsize = ft_lstsize(node);
	if (listsize <= 0)
		return (NULL);
	mat = ft_calloc(listsize + 1, sizeof(char *));
	if (!mat)
		return (NULL);
	i = 0;
	while (node)
	{
		mat[i] = node->content;
		i++;
		node = node->next;
	}
	return (mat);
}
