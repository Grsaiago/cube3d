/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:04:21 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 04:04:51 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/minilibx-linux/mlx.h"

bool	init_mlx_image(t_texture *texture, void *mlx)
{
	texture->img_ptr = mlx_xpm_file_to_image(mlx, texture->path,
			&texture->width, &texture->height);
	if (texture->img_ptr == NULL)
		return (true);
	texture->addr = (int *)mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->size_len, &texture->endian);
	return (0);
}

void	free_texture(t_data *data, t_texture *texture)
{
	free(texture->path);
	if (texture->img_ptr)
		mlx_destroy_image(data->mlx, texture->img_ptr);
	return ;
}

void	image_init(t_data *data)
{
	data->window = mlx_new_window(data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	data->image.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bpp, &data->image.size_len, &data->image.endian);
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image.img, 0, 0);
	return ;
}

void	set_ray_direction(t_data *data, t_raycast *aux)
{
	if (aux->raydirx < 0)
	{
		aux->stepx = -1;
		aux->sidedistx = (data->player_x - aux->mapx) * aux->deltadistx;
	}
	else
	{
		aux->stepx = 1;
		aux->sidedistx = (aux->mapx + 1.0 - data->player_x) * aux->deltadistx;
	}
	if (aux->raydiry < 0)
	{
		aux->stepy = -1;
		aux->sidedisty = (data->player_y - aux->mapy) * aux->deltadisty;
	}
	else
	{
		aux->stepy = 1;
		aux->sidedisty = (aux->mapy + 1.0 - data->player_y) * aux->deltadisty;
	}
	return ;
}

void	perform_dda(t_data *data, t_raycast *aux)
{
	while (42)
	{
		if (aux->sidedistx < aux->sidedisty)
		{
			aux->sidedistx += aux->deltadistx;
			aux->mapx += aux->stepx;
			aux->side = 0;
		}
		else
		{
			aux->sidedisty += aux->deltadisty;
			aux->mapy += aux->stepy;
			aux->side = 1;
		}
		if (data->map[aux->mapy][aux->mapx] == '1')
			break ;
	}
	return ;
}
