/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:55:49 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 04:10:33 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
