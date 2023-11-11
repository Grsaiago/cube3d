/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:56:23 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 03:57:27 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/minilibx-linux/mlx.h"

int	mat_to_rgb(char **mat)
{
	int	rgb;

	rgb = 0;
	rgb |= ft_atoi(mat[0]) << 16;
	rgb |= ft_atoi(mat[1]) << 8;
	rgb |= ft_atoi(mat[2]) << 0;
	return (rgb);
}

int	validate_coordinate_size(char **mat, int size)
{
	if (!mat)
		return (perror("Error!\nMalloc failed"), 1);
	if (ft_mat_size(mat) != size)
	{
		errno = E2BIG;
		return (perror("Error!\nIncorrect number of args on parameter"), 1);
	}
	return (0);
}

int	validate_cf_numbers(char **mat)
{
	int	numb;

	if (!mat)
		return (1);
	while (*mat)
	{
		if (ft_isnumstr(*mat) != 0)
		{
			errno = EINVAL;
			return (perror("Error!\nNan in RGB definition (C or F)"), 1);
		}
		numb = ft_atoi(*mat);
		if (numb < 0 || numb > 255)
		{
			errno = EINVAL;
			return (perror("Error!\nNumber not in RGB range"), 1);
		}
		mat++;
	}
	return (0);
}

int	load_params(t_list **lst, t_data *data)
{
	t_list	*aux;

	aux = *lst;
	while (aux)
	{
		if ((load_no(aux, data) != 0) || (load_so(aux, data) != 0)
			|| (load_we(aux, data) != 0) || (load_ea(aux, data) != 0)
			|| (load_f(aux, data) != 0) || (load_c(aux, data) != 0)
			|| (load_map(aux, data) != 0))
		{
			free(data->no_texture.path);
			free(data->so_texture.path);
			free(data->we_texture.path);
			return (free(data->ea_texture.path), ft_free_mat(data->map), 1);
		}
		aux = aux->next;
	}
	if (!data->no_texture.path || !data->so_texture.path
		|| !data->we_texture.path || !data->ea_texture.path
		|| !data->fok || !data->cok || !data->map)
		return (perror("Error!\nUndefined param"), 1);
	if (init_mlx_instances(data) != 0)
		return (1);
	return (ft_lstclear(lst, free), image_init(data), 0);
}

int	load_no(t_list *head, t_data *data)
{
	char	**mat;

	if (!data->no_texture.path && !(head->content[0] == '\0'
			|| ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "NO ", 3) != 0)
		return (0);
	if (data->no_texture.path)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of no"), 1);
	}
	mat = ft_split(head->content, ' ');
	if (validate_coordinate_size(mat, 2) != 0)
		return (ft_free_mat(mat), 1);
	data->no_texture.path = mat[1];
	free(mat[0]);
	free(mat);
	return (0);
}
