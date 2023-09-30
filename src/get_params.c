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

int	mat_to_rgb(char **mat, t_rgb *rgb)
{
	rgb->r = ft_atoi(mat[0]);
	rgb->g = ft_atoi(mat[1]);
	rgb->b = ft_atoi(mat[2]);
	return (0);
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

int	load_params(t_list *lst, t_data *data)
{
	while (lst)
	{
		if ((load_no(lst, data) != 0) || (load_so(lst, data) != 0)
			|| (load_we(lst, data) != 0) || (load_ea(lst, data) != 0)
			|| (load_f(lst, data) != 0) || (load_c(lst, data) != 0)
			|| (load_map(lst, data) != 0))
		{
			free(data->no_texture.path);
			free(data->so_texture.path);
			free(data->we_texture.path);
			free(data->ea_texture.path);
			ft_free_mat(data->map);
			return (1);
		}
		lst = lst->next;
	}
	if (!data->no_texture.path || !data->so_texture.path
		|| !data->we_texture.path || !data->ea_texture.path
		|| !data->fok || !data->cok || !data->map)
		return (perror("Error!\nUndefined param"), 1);
	if (init_mlx_instances(data) != 0)
		return (1);
	image_init(data);
	return (0);
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
	mat_to_rgb(mat, &data->f);
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
	mat_to_rgb(mat, &data->c);
	ft_free_mat(mat);
	data->cok = 1;
	return (0);
}

int	load_map(t_list *head, t_data *data)
{
	char	*line;
	int		aux;

	if (!data->no_texture.path || !data->so_texture.path || !data->we_texture.path || !data->ea_texture.path
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
		max_len = ((aux_len > max_len) * aux_len) + ((max_len >= aux_len) * max_len);
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
		return (perror("Error! something went wrong on img initialization"), 1);
	}
	return (false);
}

bool	init_mlx_image(t_texture *texture, void *mlx)
{
	texture->img_ptr = mlx_xpm_file_to_image(mlx, texture->path, &texture->width, &texture->height);
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
	if (texture->addr)
		free(texture->addr);
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
	mlx_put_image_to_window(data->mlx, data->window, data->image.img, 0, 0);
	return ;
}
