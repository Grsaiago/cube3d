/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:31:31 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/20 22:03:25 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	mat_to_rgb(char **mat, t_rgb *rgb)
{
	rgb->r = ft_atoi(mat[0]);
	rgb->g = ft_atoi(mat[1]);
	rgb->b = ft_atoi(mat[2]);
	return (0);
}

int	cb_validate_coordinate_size(char **mat, int size)
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

int	cb_validate_cf_numbers(char **mat)
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


int	cb_load_params(t_list *lst, t_data *data)
{
	while (lst)
	{
		if ((cb_load_no(lst, data) != 0) || (cb_load_so(lst, data) != 0)
			|| (cb_load_we(lst, data) != 0) || (cb_load_ea(lst, data) != 0)
			|| (cb_load_f(lst, data) != 0) || (cb_load_c(lst, data) != 0)
			|| (cb_load_map(lst, data) != 0))
			{
				if (data->NO)
					free(data->NO);
				if (data->SO)
					free(data->SO);
				if (data->WE)
					free(data->WE);
				if (data->EA)
					free(data->EA);
				if (data->map)
					ft_free_mat(data->map);
				return (1);
			}
		lst = lst->next;
	}
	if (!data->NO || !data->SO || !data->WE || !data->EA
			|| !data->FOK || !data->COK || !data->map)
		return (perror("Error!\nUndefined param"), 1);
	return (0);
}

int	cb_load_no(t_list *head, t_data *data)
{
	char	**mat;

	if (!data->NO && !(head->content[0]  == '\0' || ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "NO ", 3) != 0)
		return (0);
	if (data->NO)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of NO"), 1);
	}
	mat = ft_split(head->content, ' ');
	if (cb_validate_coordinate_size(mat, 2) != 0)
		return (ft_free_mat(mat), 1);
	data->NO = mat[1];
	free(mat[0]);
	free(mat);
	return (0);
}

int	cb_load_so(t_list *head, t_data *data)
{
	char	**mat;

	if (!data->SO && !(head->content[0]  == '\0' || ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "SO ", 3) != 0)
		return (0);
	if (data->SO)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of SO"), 1);
	}
	mat = ft_split(head->content, ' ');
	if (cb_validate_coordinate_size(mat, 2) != 0)
		return (ft_free_mat(mat), 1);
	data->SO = mat[1];
	free(mat[0]);
	free(mat);
	return (0);
}

int	cb_load_we(t_list *head, t_data *data)
{
	char	**mat;

	if (!data->WE && !(head->content[0]  == '\0' || ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "WE ", 3) != 0)
		return (0);
	if (data->WE)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of WE"), 1);
	}
	mat = ft_split(head->content, ' ');
	if (cb_validate_coordinate_size(mat, 2) != 0)
		return (ft_free_mat(mat), 1);
	data->WE = mat[1];
	free(mat[0]);
	free(mat);
	return (0);
}

int	cb_load_ea(t_list *head, t_data *data)
{
	char	**mat;

	if (!data->EA && !(head->content[0]  == '\0' || ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "EA ", 3) != 0)
		return (0);
	if (data->EA)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of EA"), 1);
	}
	mat = ft_split(head->content, ' ');
	if (cb_validate_coordinate_size(mat, 2) != 0)
		return (ft_free_mat(mat), 1);
	data->EA = mat[1];
	free(mat[0]);
	free(mat);
	return (0);
}

int	cb_load_f(t_list *head, t_data *data)
{
	char	**mat;
	char	*line;

	if (!data->FOK && !(head->content[0]  == '\0' || ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "F ", 2) != 0)
		return (0);
	if (data->FOK)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of F"), 1);
	}
	line = ft_strchr(head->content, ' ');
	while (ft_isspace(*line))
		line++;
	mat = ft_split(line, ',');
	if (cb_validate_coordinate_size(mat, 3)
			|| cb_validate_cf_numbers(mat))
		return (ft_free_mat(mat), 1);
	mat_to_rgb(mat, &data->F);
	ft_free_mat(mat);
	data->FOK = 1;
	return (0);
}

int	cb_load_c(t_list *head, t_data *data)
{
	char	**mat;
	char	*line;

	if (!data->COK && !(head->content[0]  == '\0' || ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "C ", 2) != 0)
		return (0);
	if (data->COK)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of C"), 1);
	}
	line = ft_strchr(head->content, ' ');
	while (ft_isspace(*line))
		line++;
	mat = ft_split(line, ',');
	if (cb_validate_coordinate_size(mat, 3)
			|| cb_validate_cf_numbers(mat))
		return (ft_free_mat(mat), 1);
	mat_to_rgb(mat, &data->C);
	ft_free_mat(mat);
	data->COK = 1;
	return (0);
}

int	cb_load_map(t_list *head, t_data *data)
{
	char	*line;
	int		aux;

	if (!data->NO || !data->SO || !data->WE || !data->EA
			|| !data->FOK || !data->COK || data->map)
		return (0);
	data->map_height = cb_get_map_height(head);
	if (data->map_height < 0)
		return (1);
	data->map = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!data->map)
		return (1);
	while (head)
	{
		line = head->content;
		while (ft_isspace(*line))
			line++;
		if (*line == '1')
			break ;
		head = head->next;
	}
	aux = 0;
	while (aux < data->map_height)
	{
		data->map[aux] = ft_strdup(head->content, 0);
		if (!data->map[aux])
			return (perror("Error!\nMalloc error on map loading"), 1);
		head = head->next;
		aux++;
	}
	if (cb_validate_map(data) != 0)
		return (1);
	return (0);
}

int	cb_get_map_height(t_list *head)
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
	while(head && ft_strlen(head->content) > 1)
	{
		i++;
		head = head->next;
	}
	if (i < 3)
		return (perror("Error!\nThe map must have at least 3 lines"), -1);
	return (i);
}
