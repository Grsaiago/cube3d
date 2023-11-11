/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:07:10 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 04:07:45 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/minilibx-linux/mlx.h"

void	hooks_init(t_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->window, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->window, 17, 0L << 0, close_window, data);
	mlx_hook(data->window, 3, 1L << 1, key_released, data);
	mlx_loop_hook(data->mlx, hook, data);
	mlx_loop(data->mlx);
}

int	validate_args(int argc, char **argv)
{
	int	fd;

	if ((argc != 2) || (ft_strlen(argv[1]) < 4)
		|| (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 5)))
	{
		errno = EINVAL;
		return (perror("Error!\nMust be a readable file ending in .cub"), -1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		errno = EBADF;
		return (perror("Error!\nOpen failed"), -1);
	}
	return (fd);
}

void	initialize_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->player_x = -1;
	data->player_y = -1;
	return ;
}
