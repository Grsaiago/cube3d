/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:36:03 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 04:08:21 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;
	t_list	*head;

	fd = validate_args(argc, argv);
	if (fd < 0)
		return (0);
	initialize_data(&data);
	head = ft_read_file(fd, FT_LST | FT_NON);
	if (!head)
	{
		errno = ENOENT;
		return (perror("Error!\n File read error"), EXIT_FAILURE);
	}
	if (load_params(&head, &data) != 0)
		return (1);
	hooks_init(&data);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->image.img);
	free_texture(data, &data->no_texture);
	free_texture(data, &data->so_texture);
	free_texture(data, &data->we_texture);
	free_texture(data, &data->ea_texture);
	ft_free_mat(data->map);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else if (keycode == W)
		data->walk_direction++;
	else if (keycode == A)
		data->turn_direction++;
	else if (keycode == S)
		data->walk_direction--;
	else if (keycode == D)
		data->turn_direction--;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == W)
		data->walk_direction--;
	else if (keycode == A)
		data->turn_direction--;
	else if (keycode == S)
		data->walk_direction++;
	else if (keycode == D)
		data->turn_direction++;
	return (0);
}
