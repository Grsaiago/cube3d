/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:55:49 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/28 14:51:19 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		validate_map(t_data *data);
int		validate_top_bottom(t_data *data);
int		validate_sides(t_data *data);
int		validate_interior(t_data *data);
void	get_above_below(t_data *data, int line_numb, int *above, int *below);
int		player_p(t_data *data, const char c, int width, int height);
void	set_player_direction(t_data *data);
void	set_player_plane(t_data *data);

typedef struct s_map_interior_validation_aux
{
	int		line_numb;
	char	*line;
	int		above;
	int		below;
	int		i;
}	t_map_interior_validation_aux;

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

int	player_p(t_data *data, const char c, int width, int height)
{
	if (data->spawn_direction)
		return (perror("Error!\nPlayer spawn double definition"), 1);
	data->spawn_direction = c;
	data->player_x = width + 0.5;
	data->player_y = height + 0.5;
	set_player_direction(data);
	set_player_plane(data);
	return (0);
}

void	set_player_direction(t_data *data)
{
	if (data->spawn_direction == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (data->spawn_direction == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	else if (data->spawn_direction == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	else if (data->spawn_direction == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	return ;
}

void	set_player_plane(t_data *data)
{
	if (data->spawn_direction == 'N')
	{
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else if (data->spawn_direction == 'S')
	{
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (data->spawn_direction == 'W')
	{
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	else if (data->spawn_direction == 'E')
	{
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	return ;
}
