/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:36:03 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/28 14:19:19 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize_data(t_data *data);
int		key_pressed(int keycode, t_data *data);
int		key_released(int keycode, t_data *data);
int 	close_window(t_data *data);
void	image_init(t_data *data);
int		hook(t_data *data);

static void	hooks_init(t_data *data)
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
	if (load_params(head, &data) != 0) // tem que guardar o x e y de spawn do player
		return (1);
	// OK - settar as imagens da mlx (o load_texture deles)
	// OK - settar a posição do player igual o set_player_direction (pensa num plano cartesiano pra esses x y)
	//  TEM QUE FAZER -  settar a câmera do player igual o set_player_plane deles. Isso setta o FOV
	// OK - settar o a posição do player igual o set_player_position deles. O player->pos_x += 0.5 é pra spawnar no meio do quadrado
	// OK - image_init deles p/criar a primeira imagem - abrir a janela, cirar uma nova imagem (pq não podemos jogar os pixels na tela), 
	// hooks_init vai inicializar as os hooks de tecla e chamar a mlx_loop_hook pra executar sempre a função 'hook'
	// passando o data como parametro pra ela.
	// na hooks init ele tem os hooks de keypressed e keyreleased, que são usados pra saber se o player tá andando e
	// pra qual direção ele está andando. Esses walk_direction e turn_direction são usados na update_player p/calcular a
	// nova posição.
	hooks_init(&data);
	ft_lstclear(&head, free);
	return (0);
}

__attribute__((noreturn))
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
