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

#include "./cub3d.h"

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

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;
	t_list	*head;

	fd = validate_args(argc, argv);
	if (fd < 0)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	head = ft_read_file(fd, FT_LST | FT_NON);
	load_params(head, &data);
	ft_lstclear(&head, free);
}
