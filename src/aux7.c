/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:09:10 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 04:10:32 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	validate_map(t_data *data)
{
	if (validate_top_bottom(data))
		return (1);
	else if (validate_sides(data))
		return (1);
	else if (validate_interior(data))
		return (1);
	return (0);
}

int	validate_top_bottom(t_data *data)
{
	char	*line;

	line = data->map[0];
	while (*line)
	{
		if (ft_strchr("1 \t\r", *line) == NULL)
			return (perror("Error!\nInvalid char at map top"), 1);
		line++;
	}
	line = data->map[data->map_height - 1];
	while (*line)
	{
		if (ft_strchr("1 \t\r", *line) == NULL)
			return (perror("Error!\nInvalid char at map bottom"), 1);
		line++;
	}
	return (0);
}

int	validate_sides(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = data->map[0];
	while (line)
	{
		while (ft_isspace(*line))
			line++;
		if ((*line != '1') || (line[ft_strlen(line) - 1] != '1'))
			return (perror("Error!\nInvalid char in some side"), 1);
		i++;
		line = data->map[i];
	}
	return (0);
}

int	validate_interior(t_data *data)
{
	t_map_interior_validation_aux	ax;

	ax.line_numb = 1;
	ax.line = data->map[1];
	while (ax.line && ax.line_numb < data->map_height)
	{
		get_above_below(data, ax.line_numb, &ax.above, &ax.below);
		ax.i = 0;
		while (ax.line[++ax.i] && (ax.i < (int)ft_strlen(ax.line) - 1))
		{
			if (ax.line[ax.i] == '0' && (ax.i > ax.above || ax.i > ax.below
					|| data->map[ax.line_numb - 1][ax.i] == ' '
				|| data->map[ax.line_numb + 1][ax.i] == ' '
				|| ax.line[ax.i - 1] == ' ' || ax.line[ax.i + 1] == ' '))
				return (perror("Error!\nNonvalid '0' placement"), 1);
			else if (ft_strchr("NSWE", ax.line[ax.i]) && player_p(data,
					ax.line[ax.i], ax.i, ax.line_numb))
				return (EXIT_FAILURE);
		}
		ax.line_numb++;
		ax.line = data->map[ax.line_numb];
	}
	if (data->player_x == -1 || data->player_y == -1)
		return (perror("Error! Invalid or no player position"), 1);
	return (EXIT_SUCCESS);
}

void	get_above_below(t_data *data, int line_numb, int *above, int *below)
{
	if (line_numb == 0)
		*above = 0;
	else
		*above = ft_strlen(data->map[line_numb - 1]);
	if (line_numb == data->map_height)
		*below = 0;
	else
		*below = ft_strlen(data->map[line_numb + 1]);
	return ;
}
