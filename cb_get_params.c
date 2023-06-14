/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:31:31 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/14 15:31:32 by gsaiago          ###   ########.fr       */
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
	if ((cb_load_no(lst, data) != 0) || (cb_load_so(lst, data) != 0)
		|| (cb_load_we(lst, data) != 0) || (cb_load_ea(lst, data) != 0)
		|| (cb_load_f(lst, data) != 0) || (cb_load_c(lst, data) != 0))
		{
			if (data->NO)
				free(data->NO);
			if (data->SO)
				free(data->SO);
			if (data->WE)
				free(data->WE);
			if (data->EA)
				free(data->EA);
			return (1);
		}
	/*
	else if (cb_get_map(lst, data) != 0)
		return (1);
		*/
	return (0);
}

int	cb_load_no(t_list *head, t_data *data)
{
	char	**mat;

	while (head)
	{
		if (ft_strncmp(head->content, "NO ", 3) == 0)
		{
			mat = ft_split(head->content, ' ');
			if (cb_validate_coordinate_size(mat, 2) != 0)
				return (ft_free_mat(mat), 1);
			data->NO = mat[1];
			free(mat[0]);
			free(mat);
			return (0);
		}
		head = head->next;
	}
	errno = EINVAL;
	return (perror("Error!\nNo 'NO' parameter"), 1);
}

int	cb_load_so(t_list *head, t_data *data)
{
	char	**mat;

	while (head)
	{
		if (ft_strncmp(head->content, "SO ", 3) == 0)
		{
			mat = ft_split(head->content, ' ');
			if (cb_validate_coordinate_size(mat, 2) != 0)
				return (ft_free_mat(mat), 1);
			data->SO = mat[1];
			free(mat[0]);
			free(mat);
			return (0);
		}
		head = head->next;
	}
	errno = EINVAL;
	return (perror("Error!\nNo 'SO' parameter"), 1);
}

int	cb_load_we(t_list *head, t_data *data)
{
	char	**mat;

	while (head)
	{
		if (ft_strncmp(head->content, "WE ", 3) == 0)
		{
			mat = ft_split(head->content, ' ');
			if (cb_validate_coordinate_size(mat, 2) != 0)
				return (ft_free_mat(mat), 1);
			data->WE = mat[1];
			free(mat[0]);
			free(mat);
			return (0);
		}
		head = head->next;
	}
	errno = EINVAL;
	return (perror("Error!\nNo 'WE' parameter"), 1);
}

int	cb_load_ea(t_list *head, t_data *data)
{
	char	**mat;

	while (head)
	{
		if (ft_strncmp(head->content, "EA ", 3) == 0)
		{
			mat = ft_split(head->content, ' ');
			if (cb_validate_coordinate_size(mat, 2) != 0)
				return (ft_free_mat(mat), 1);
			data->EA = mat[1];
			free(mat[0]);
			free(mat);
			return (0);
		}
		head = head->next;
	}
	errno = EINVAL;
	return (perror("Error!\nNo 'EA' parameter"), 1);
}

int	cb_load_f(t_list *head, t_data *data)
{
	char	**mat;
	char	*line;

	while (head)
	{
		if (ft_strncmp(head->content, "F ", 2) == 0)
		{
			line = ft_strchr(head->content, ' ');
			while (ft_isspace(*line))
				line++;
			mat = ft_split(line, ',');
			if (cb_validate_coordinate_size(mat, 3)
					|| cb_validate_cf_numbers(mat))
				return (ft_free_mat(mat), 1);
			mat_to_rgb(mat, &data->F);
			return (0);
		}
		head = head->next;
	}
	errno = EINVAL;
	return (perror("Error!\nNo 'F' parameter"), 1);
}

int	cb_load_c(t_list *head, t_data *data)
{
	char	**mat;
	char	*line;

	while (head)
	{
		if (ft_strncmp(head->content, "C ", 2) == 0)
		{
			line = ft_strchr(head->content, ' ');
			while (ft_isspace(*line))
				line++;
			mat = ft_split(line, ',');
			if (cb_validate_coordinate_size(mat, 3)
					|| cb_validate_cf_numbers(mat))
				return (ft_free_mat(mat), 1);
			mat_to_rgb(mat, &data->C);
			ft_free_mat(mat);
			return (0);
		}
		head = head->next;
	}
	errno = EINVAL;
	return (perror("Error!\nNo 'C' parameter"), 1);
}
