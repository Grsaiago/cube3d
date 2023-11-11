/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:01:43 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 04:01:52 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/minilibx-linux/mlx.h"

void	load_map_aux(t_list *head, t_data *data)
{
	int	aux;

	aux = 0;
	while (aux < data->map_height)
	{
		data->map[aux] = ft_strdup(head->content, 0);
		head = head->next;
		aux++;
	}
	return ;
}

int	load_map(t_list *head, t_data *data)
{
	char	*line;

	if (!data->no_texture.path || !data->so_texture.path
		|| !data->we_texture.path || !data->ea_texture.path
		|| !data->fok || !data->cok || data->map)
		return (0);
	data->map_height = get_map_height(head);
	data->map_width = get_map_width(head);
	if (data->map_height < 0)
		return (1);
	data->map = ft_calloc(data->map_height + 1, sizeof(char *));
	while (head)
	{
		line = head->content;
		while (ft_isspace(*line))
			line++;
		if (*line == '1')
			break ;
		head = head->next;
	}
	load_map_aux(head, data);
	if (validate_map(data) != 0)
		return (1);
	return (0);
}

int	get_map_width(t_list *head)
{
	unsigned int	max_len;
	unsigned int	aux_len;

	max_len = 0;
	while (head)
	{
		aux_len = ft_strlen(head->content);
		max_len = ((aux_len > max_len) * aux_len)
			+ ((max_len >= aux_len) * max_len);
		head = head->next;
	}
	return (max_len);
}

int	get_map_height(t_list *head)
{
	int		i;
	char	*line;

	while (head)
	{
		line = head->content;
		while (ft_isspace(*line))
			line++;
		if (*line == '1')
			break ;
		head = head->next;
	}
	if (!head)
		return (perror("Error!\nThere is no valid map"), -1);
	i = 0;
	while (head && ft_strlen(head->content) > 1)
	{
		i++;
		head = head->next;
	}
	if (i < 3)
		return (perror("Error!\nThe map must have at least 3 lines"), -1);
	return (i);
}

bool	init_mlx_instances(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx
		|| init_mlx_image(&data->no_texture, data->mlx)
		|| init_mlx_image(&data->so_texture, data->mlx)
		|| init_mlx_image(&data->we_texture, data->mlx)
		|| init_mlx_image(&data->ea_texture, data->mlx))
	{
		errno = EINVAL;
		free_texture(data, &data->no_texture);
		free_texture(data, &data->so_texture);
		free_texture(data, &data->we_texture);
		free_texture(data, &data->ea_texture);
		ft_free_mat(data->map);
		free(data->mlx);
		return (perror("Error! something went wrong on img initialization"), 1);
	}
	return (false);
}
