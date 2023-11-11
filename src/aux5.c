/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:05:26 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 04:05:47 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/minilibx-linux/mlx.h"

void	raycast_aux(t_data *data, t_raycast *aux)
{
	if (aux->side == 0)
	{
		data->dist_buffer[aux->x] = (aux->sidedistx - aux->deltadistx);
		if (aux->raydirx < 0)
			data->ray_hit_direction = 'W';
		else
			data->ray_hit_direction = 'E';
	}
	else
	{
		data->dist_buffer[aux->x] = (aux->sidedisty - aux->deltadisty);
		if (aux->raydiry < 0)
			data->ray_hit_direction = 'N';
		else
			data->ray_hit_direction = 'S';
	}
	return ;
}

void	raycast_aux_refresh_values(t_data *data, t_raycast *aux)
{
	aux->camerax = 2 * aux->x / (double)WINDOW_WIDTH - 1;
	aux->raydirx = data->dir_x + data->plane_x * aux->camerax;
	aux->raydiry = data->dir_y + data->plane_y * aux->camerax;
	aux->mapx = data->player_x;
	aux->mapy = data->player_y;
	if (aux->raydirx == 0)
		aux->deltadistx = 1e30;
	else
		aux->deltadistx = fabs(1 / aux->raydirx);
	if (aux->raydiry == 0)
		aux->deltadistx = 1e30;
	else
		aux->deltadisty = fabs(1 / aux->raydiry);
	return ;
}

void	raycast(t_data *data)
{
	t_raycast	a;

	ft_memset(&a, 0, sizeof(t_raycast));
	while (a.x < WINDOW_WIDTH)
	{
		raycast_aux_refresh_values(data, &a);
		set_ray_direction(data, &a);
		perform_dda(data, &a);
		raycast_aux(data, &a);
		if (data->ray_hit_direction == 'N' || data->ray_hit_direction == 'S')
			data->wall_x = data->player_x + data->dist_buffer[a.x] * a.raydirx;
		else
			data->wall_x = data->player_y + data->dist_buffer[a.x] * a.raydiry;
		data->wall_x -= (int)data->wall_x;
		a.image_to_paint = select_image_to_paint(data);
		data->texture_x = (int)(data->wall_x * (double)a.image_to_paint->width);
		if (data->ray_hit_direction == 'S')
			data->texture_x = a.image_to_paint->width - data->texture_x - 1;
		else if (data->ray_hit_direction == 'W')
			data->texture_x = a.image_to_paint->width - data->texture_x - 1;
		paint_image(data, a.x, a.image_to_paint);
		a.x++;
	}
}

t_texture	*select_image_to_paint(t_data *data)
{
	if (data->ray_hit_direction == 'N')
		return (&data->no_texture);
	else if (data->ray_hit_direction == 'S')
		return (&data->so_texture);
	else if (data->ray_hit_direction == 'W')
		return (&data->we_texture);
	else if (data->ray_hit_direction == 'E')
		return (&data->ea_texture);
	return (&data->ea_texture);
}

void	paint_image(t_data *data, int x, t_texture *image_to_paint)
{
	t_paint_image_aux	aux;

	ft_memset(&aux, 0, sizeof(t_paint_image_aux));
	aux.line_height = (int)(WINDOW_HEIGHT / data->dist_buffer[x]);
	aux.draw_start = -aux.line_height / 2 + WINDOW_HEIGHT / 2;
	aux.color = 0xFF0000;
	if (aux.draw_start < 0)
		aux.draw_start = 0;
	aux.draw_end = aux.line_height / 2 + WINDOW_HEIGHT / 2;
	if (aux.draw_end >= WINDOW_HEIGHT)
		aux.draw_end = WINDOW_HEIGHT - 1;
	aux.step = 1.0 * image_to_paint->height / aux.line_height;
	aux.texture_pos = aux.step
		* (int)(aux.draw_start - WINDOW_HEIGHT / 2 + aux.line_height / 2);
	paint_image_aux(data, x, image_to_paint, &aux);
	return ;
}
