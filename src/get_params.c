/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:31:31 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 04:05:39 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/minilibx-linux/mlx.h"

void	paint_image_aux(t_data *dt, int x, t_texture *img, t_paint_image_aux *a)
{
	int	y;

	y = 0;
	while (y < a->draw_start)
	{
		put_pixel(&dt->image, x, y, dt->c_color);
		y++;
	}
	y = a->draw_end;
	while (y < WINDOW_HEIGHT)
	{
		put_pixel(&dt->image, x, y, dt->f_color);
		y++;
	}
	y = a->draw_start;
	while (y < a->draw_end)
	{
		a->texture_y = (int)a->texture_pos & (img->height - 1);
		a->texture_pos += a->step;
		a->color = img->addr[(img->height * a->texture_y
				+ dt->texture_x)];
		put_pixel(&dt->image, x, y, a->color);
		y++;
	}
	return ;
}

void	put_pixel(t_image *image, int x, int y, unsigned int color)
{
	char	*dst;

	dst = image->addr + (y * image->size_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	update_player(t_data *data)
{
	t_update_player	aux;

	ft_memset(&aux, 0, sizeof(t_update_player));
	aux.rot_angle = data->turn_direction * ROTATION_SPEED;
	aux.old_dir_x = data->dir_x;
	aux.old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(aux.rot_angle)
		- data->dir_y * sin(aux.rot_angle);
	data->dir_y = aux.old_dir_x * sin(aux.rot_angle)
		+ data->dir_y * cos(aux.rot_angle);
	data->plane_x = data->plane_x * cos(aux.rot_angle)
		- data->plane_y * sin(aux.rot_angle);
	data->plane_y = aux.old_plane_x * sin(aux.rot_angle)
		+ data->plane_y * cos(aux.rot_angle);
	aux.move_step = data->walk_direction * MOVE_SPEED;
	aux.next_x = data->player_x + (data->dir_x * aux.move_step);
	aux.next_y = data->player_y + (data->dir_y * aux.move_step);
	if (data->map[(size_t)data->player_y][(size_t)aux.next_x] != '1')
		data->player_x = aux.next_x;
	if (data->map[(size_t)aux.next_y][(size_t)data->player_x] != '1')
		data->player_y = aux.next_y;
	return ;
}

int	hook(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	update_player(data);
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image.img, 0, 0);
	return (0);
}
