/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:55:49 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/13 17:44:06 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

typedef struct s_vparams
{
	unsigned int	character_line;
	unsigned int	map_height;
	unsigned int	map_width;
}	t_vparams;

t_list	*cb_get_raw_map(int	fd, t_vparams *params)
{
	t_list	*head;
	t_list	*node;
	char	*line;

	if (fd < 0)
		return (perror("Error on open"), NULL);
	head = NULL;
	line = get_next_line(fd);
	if (!line)
		return (perror("Empty map"), NULL);
	while (line)
	{
		params->map_height++;
		if (ft_strlen(line) > params->map_width)
			params->map_width = ft_strlen(line);
		node = ft_lstnew(line);
		if (!node)
			return (ft_lstclear(&head, free), NULL);
		ft_lstadd_back(&head, node);
		line = get_next_line(fd);
	}
	return (head);
}

char	**cb_validate_map(t_list **head)
{
	char		**map;
	int			i;

	if (!head || !*head)
		return (NULL);
	map = ft_lst_to_mat(*head);
	ft_lstclear(head, NULL);
	if (!map)
		return (perror("Error!\nError on malloc"), NULL);
	i = 0;
	while (map[i])
	{
		if (cb_validate_map_line(map, i))
		{
			ft_free_mat(map);
			return (perror("Error!\nError on line validation"), NULL);
		}
		i++;
	}
	return (map);
}

int	cb_validate_map_line(char **map, int line_numb)
{
	int		i;
	char	*line;

	i = 0;
	line = map[line_numb];
	//fazer a validação de linha de acordo com oq o gguedes me falou caraio
	return (0);
}
