/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:31:31 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/28 14:08:48 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/minilibx-linux/mlx.h"

int		get_map_width(t_list *head);
void	image_init(t_data *data);
void	raycast(t_data *data);
void	paint_image(t_data *data, int x, t_texture *image_to_paint);
void	put_pixel(t_image *image, int x, int y, unsigned int color);

int	mat_to_rgb(char **mat)
{
	int	rgb;

	rgb = 0;
	rgb |= ft_atoi(mat[0]) << 16;
	rgb |= ft_atoi(mat[1]) << 8;
	rgb |= ft_atoi(mat[2]) << 0;
	return (rgb);
}

int	validate_coordinate_size(char **mat, int size)
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

int	validate_cf_numbers(char **mat)
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

int	load_params(t_list **lst, t_data *data)
{
	t_list	*aux;

	aux = *lst;
	while (aux)
	{
		if ((load_no(aux, data) != 0) || (load_so(aux, data) != 0)
			|| (load_we(aux, data) != 0) || (load_ea(aux, data) != 0)
			|| (load_f(aux, data) != 0) || (load_c(aux, data) != 0)
			|| (load_map(aux, data) != 0))
		{
			free(data->no_texture.path);
			free(data->so_texture.path);
			free(data->we_texture.path);
			return (free(data->ea_texture.path), ft_free_mat(data->map), 1);
		}
		aux = aux->next;
	}
	if (!data->no_texture.path || !data->so_texture.path
		|| !data->we_texture.path || !data->ea_texture.path
		|| !data->fok || !data->cok || !data->map)
		return (perror("Error!\nUndefined param"), 1);
	if (init_mlx_instances(data) != 0)
		return (1);
	return (ft_lstclear(lst, free), image_init(data), 0);
}

int	load_no(t_list *head, t_data *data)
{
	char	**mat;

	if (!data->no_texture.path && !(head->content[0] == '\0'
			|| ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "NO ", 3) != 0)
		return (0);
	if (data->no_texture.path)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of no"), 1);
	}
	mat = ft_split(head->content, ' ');
	if (validate_coordinate_size(mat, 2) != 0)
		return (ft_free_mat(mat), 1);
	data->no_texture.path = mat[1];
	free(mat[0]);
	free(mat);
	return (0);
}

int	load_so(t_list *head, t_data *data)
{
	char	**mat;

	if (!data->so_texture.path && !(head->content[0] == '\0'
			|| ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "SO ", 3) != 0)
		return (0);
	if (data->so_texture.path)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of so"), 1);
	}
	mat = ft_split(head->content, ' ');
	if (validate_coordinate_size(mat, 2) != 0)
		return (ft_free_mat(mat), 1);
	data->so_texture.path = mat[1];
	free(mat[0]);
	free(mat);
	return (0);
}

int	load_we(t_list *head, t_data *data)
{
	char	**mat;

	if (!data->we_texture.path && !(head->content[0] == '\0'
			|| ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "WE ", 3) != 0)
		return (0);
	if (data->we_texture.path)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of we"), 1);
	}
	mat = ft_split(head->content, ' ');
	if (validate_coordinate_size(mat, 2) != 0)
		return (ft_free_mat(mat), 1);
	data->we_texture.path = mat[1];
	free(mat[0]);
	free(mat);
	return (0);
}

int	load_ea(t_list *head, t_data *data)
{
	char	**mat;

	if (!data->ea_texture.path && !(head->content[0] == '\0'
			|| ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "EA ", 3) != 0)
		return (0);
	if (data->ea_texture.path)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of ea"), 1);
	}
	mat = ft_split(head->content, ' ');
	if (validate_coordinate_size(mat, 2) != 0)
		return (ft_free_mat(mat), 1);
	data->ea_texture.path = mat[1];
	free(mat[0]);
	free(mat);
	return (0);
}

int	load_f(t_list *head, t_data *data)
{
	char	**mat;
	char	*line;

	if (!data->fok && !(head->content[0] == '\0'
			|| ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "F ", 2) != 0)
		return (0);
	if (data->fok)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of F"), 1);
	}
	line = ft_strchr(head->content, ' ');
	while (ft_isspace(*line))
		line++;
	mat = ft_split(line, ',');
	if (validate_coordinate_size(mat, 3)
		|| validate_cf_numbers(mat))
		return (ft_free_mat(mat), 1);
	data->f_color = mat_to_rgb(mat);
	ft_free_mat(mat);
	data->fok = 1;
	return (0);
}

int	load_c(t_list *head, t_data *data)
{
	char	**mat;
	char	*line;

	if (!data->cok && !(head->content[0] == '\0'
			|| ft_strchr("NSWEFC", head->content[0])))
		return (perror("Error!\nUndefined conf param"), 1);
	if (ft_strncmp(head->content, "C ", 2) != 0)
		return (0);
	if (data->cok)
	{
		errno = EINVAL;
		return (perror("Error!\nDouble definition of C"), 1);
	}
	line = ft_strchr(head->content, ' ');
	while (ft_isspace(*line))
		line++;
	mat = ft_split(line, ',');
	if (validate_coordinate_size(mat, 3)
		|| validate_cf_numbers(mat))
		return (ft_free_mat(mat), 1);
	data->c_color = mat_to_rgb(mat);
	ft_free_mat(mat);
	data->cok = 1;
	return (0);
}

int	load_map(t_list *head, t_data *data)
{
	char	*line;
	int		aux;

	if (!data->no_texture.path || !data->so_texture.path
		|| !data->we_texture.path || !data->ea_texture.path
		|| !data->fok || !data->cok || data->map)
		return (0);
	data->map_height = get_map_height(head);
	data->map_width = get_map_width(head);
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
	if (validate_map(data) != 0)
		return (1);
	return (0);
}

int	get_map_width(t_list *head)
{
	unsigned int	max_len;
	unsigned int	aux_len;

	max_len = 0;
	while (head)
	{
		aux_len = ft_strlen(head->content);
		max_len = ((aux_len > max_len) * aux_len)
			+ ((max_len >= aux_len) * max_len);
		head = head->next;
	}
	return (max_len);
}

int	get_map_height(t_list *head)
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
	while (head && ft_strlen(head->content) > 1)
	{
		i++;
		head = head->next;
	}
	if (i < 3)
		return (perror("Error!\nThe map must have at least 3 lines"), -1);
	return (i);
}

// load and free of mlx instances
bool	init_mlx_instances(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx
		|| init_mlx_image(&data->no_texture, data->mlx)
		|| init_mlx_image(&data->so_texture, data->mlx)
		|| init_mlx_image(&data->we_texture, data->mlx)
		|| init_mlx_image(&data->ea_texture, data->mlx))
	{
		errno = EINVAL;
		free_texture(data, &data->no_texture);
		free_texture(data, &data->so_texture);
		free_texture(data, &data->we_texture);
		free_texture(data, &data->ea_texture);
		ft_free_mat(data->map);
		free(data->mlx);
		return (perror("Error! something went wrong on img initialization"), 1);
	}
	return (false);
}

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

// initialization on painting on screen

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

void	raycast(t_data *data)
{
	for (int x = 0; x < WINDOW_WIDTH; x++)
	{
		// DAQUI
		//calculate ray position and direction
		double		camerax = 2 * x / (double)WINDOW_WIDTH - 1; //x-coordinate in camera space
		double		raydirx = data->dir_x + data->plane_x * camerax;
		double		raydiry = data->dir_y + data->plane_y * camerax;

		//which box of the map we're in
		int 		mapx = data->player_x;
		int			mapy = data->player_y;

		//length of ray from current position to next x or y-side
		double		sidedistx;
		double		sidedisty;

		//length of ray from one x or y-side to next x or y-side
		double		deltadistx = (raydirx == 0) ? 1e30 : fabs(1 / raydirx);
		double		deltadisty = (raydiry == 0) ? 1e30 : fabs(1 / raydiry);
		// ATÉ AQUI JOGA NUMA START RAY

		//what direction to step in x or y-direction (either +1 or -1)
		int			stepx;
		int			stepy;

		int			side; //was a NS or a EW wall hit?

		t_texture	*image_to_paint;
		// DAQUI
		//calculate step and initial sideDist
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (data->player_x - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - data->player_x) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (data->player_y - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - data->player_y) * deltadisty;
		}
			// ATÉ AQUI FAZ NUMA SET RAY DIRECTION
		//perform DDA
		while (42)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			//Check if ray has hit a wall
			if (data->map[mapy][mapx] == '1')
				break ;
		}
		if (side == 0)
		{
			data->dist_buffer[x] = (sidedistx - deltadistx);
			if (raydirx < 0)
				data->ray_hit_direction= 'W';
			else
				data->ray_hit_direction= 'E';
		}
		else
		{
			data->dist_buffer[x] = (sidedisty - deltadisty);
			if (raydiry < 0)
				data->ray_hit_direction= 'N';
			else
				data->ray_hit_direction= 'S';
		}
		//calculate lowest and highest pixel to fill in current stripe
		// Set texture position inline a partir daqui
		if (data->ray_hit_direction== 'N' || data->ray_hit_direction== 'S')
			data->wall_x = data->player_x + data->dist_buffer[x] * raydirx;
		else
			data->wall_x = data->player_y + data->dist_buffer[x] * raydiry;
		data->wall_x -= (int)data->wall_x;
		if (data->ray_hit_direction== 'N')
			image_to_paint = &data->no_texture;
		else if (data->ray_hit_direction== 'S')
			image_to_paint = &data->so_texture;
		else if (data->ray_hit_direction== 'W')
			image_to_paint = &data->we_texture;
		else if (data->ray_hit_direction== 'E')
			image_to_paint = &data->ea_texture;
		data->texture_x = (int)(data->wall_x * (double)image_to_paint->width);
		if (data->ray_hit_direction== 'S')
			data->texture_x = image_to_paint->width - data->texture_x - 1;
		else if (data->ray_hit_direction== 'W')
			data->texture_x = image_to_paint->width - data->texture_x - 1;
		paint_image(data, x, image_to_paint);
	}
	//Calculate height of line to draw on screen
	return ;
}

void	paint_image(t_data *data, int x, t_texture *image_to_paint)
{
	int		texture_y;
	double	step;
	double	texture_pos;

	//Calculate height of line to draw on screen
	int		color = 0xFF0000;
	int		line_height = (int)(WINDOW_HEIGHT / data->dist_buffer[x]);

	//calculate lowest and highest pixel to fill in current stripe
	int		draw_start = -line_height/ 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	int		draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	step = 1.0 * image_to_paint->height / line_height;
	texture_pos = step * (int)(draw_start - WINDOW_HEIGHT / 2 + line_height / 2);
	// pintar o teto e o chão antes dos lados pros lados sobreporem
	for (int y = 0; y < draw_start; y++)
		put_pixel(&data->image, x, y, data->c_color);
	for (int y = draw_end; y < WINDOW_HEIGHT; y++)
		put_pixel(&data->image, x, y, data->f_color);
	for (int y = draw_start; y < draw_end; y++)
	{
		texture_y = (int)texture_pos & (image_to_paint->height - 1);
		texture_pos += step;
		color = image_to_paint->addr[(image_to_paint->height * texture_y
				+ data->texture_x)];
		put_pixel(&data->image, x, y, color);
	}
	// o draw start e o draw end são início de onde eu pinto até
	// fim de onde eu pinto (no sentido vertical).
	// Para pintar o teto e o chão é só eu fazer dois for,
	// um de 0 até drawStart e outro de drawEnd até WINDOW_HEIGHT
	return ;
}

// INLINE NA RAYCAST
/*
void    set_texture_position(t_data *data)
{
    if (data->rayHitDirection == 'N' || data->rayHitDirection == 'S')
        info->wall_x = data->player_x + data->dist_buffer[x] * data->fok;
    else
        info->wall_x = player->pos_y + ray->distance * ray->dir_y;
    info->wall_x -= (int)info->wall_x;
    get_texture(data, ray, info);
    info->texture_x = (int)(info->wall_x * (double)info->texture->width);
    if (ray->hit_direction == 'S')
        info->texture_x = info->texture->width - info->texture_x - 1;
    if (ray->hit_direction == 'W')
        info->texture_x = info->texture->width - info->texture_x - 1;
    info->step = 1.0 * info->texture->height / info->line_height;
    info->texture_pos = (info->wall_start - WINDOW_HEIGHT / 2
            + info->line_height / 2) * info->step;
}
*/

void    put_pixel(t_image *image, int x, int y, unsigned int color)
{
	char	*dst;

	dst = image->addr + (y * image->size_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void    update_player(t_data *data)
{
	float	rot_angle;
	float	old_dir_x;
	float	old_plane_x;
	float	move_step;
	float	next_x;
	float	next_y;

	rot_angle = data->turn_direction * ROTATION_SPEED;
	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(rot_angle) - data->dir_y * sin(rot_angle);
	data->dir_y = old_dir_x * sin(rot_angle) + data->dir_y * cos(rot_angle);
	data->plane_x = data->plane_x * cos(rot_angle)
		- data->plane_y * sin(rot_angle);
	data->plane_y = old_plane_x * sin(rot_angle)
		+ data->plane_y * cos(rot_angle);

	move_step = data->walk_direction * MOVE_SPEED;

	next_x = data->player_x + (data->dir_x * move_step);
	next_y = data->player_y + (data->dir_y * move_step);

	if (data->map[(size_t)data->player_y][(size_t)next_x] != '1')
		data->player_x = next_x;
	if (data->map[(size_t)next_y][(size_t)data->player_x] != '1')
		data->player_y = next_y;
}

int	hook(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	update_player(data);
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image.img, 0, 0);
	return (0);
}
