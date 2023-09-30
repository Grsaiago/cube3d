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
	load_params(head, &data); // tem que guardar o x e y de spawn do player
	// OK - settar as imagens da mlx (o load_texture deles)
	// OK - settar a posição do player igual o set_player_direction (pensa num plano cartesiano pra esses x y)
	//  ? (não achamos) - settar a câmera do player igual o set_camera_plane deles. Isso setta o FOV
	// OK - settar o a posição do player igual o set_player_position deles. O player->pos_x += 0.5 é pra spawnar no meio do quadrado
	// OK - image_init deles p/criar a primeira imagem - abrir a janela, cirar uma nova imagem (pq não podemos jogar os pixels na tela), 
	// hooks_init vai inicializar as os hooks de tecla e chamar a mlx_loop_hook pra executar sempre a função 'hook'
	// passando o data como parametro pra ela.
	// na hooks init ele tem os hooks de keypressed e keyreleased, que são usados pra saber se o player tá andando e
	// pra qual direção ele está andando. Esses walk_direction e turn_direction são usados na update_player p/calcular a
	// nova posição.
	ft_lstclear(&head, free);
}
