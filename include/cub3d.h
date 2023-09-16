/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:36:14 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/28 14:51:20 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	f;
	t_rgb	c;
	int		fok;
	int		cok;
	char	**map;
	int		map_height;
	char	spawn_direction;
}	t_data;

/* info validation */
int		load_params(t_list *lst, t_data *data);
int		load_no(t_list *head, t_data *data);
int		load_so(t_list *head, t_data *data);
int		load_we(t_list *head, t_data *data);
int		load_ea(t_list *head, t_data *data);
int		load_f(t_list *head, t_data *data);
int		load_c(t_list *head, t_data *data);
int		mat_to_rgb(char **mat, t_rgb *rgb);
int		load_map(t_list *head, t_data *data);
/* map validation */
int		validate_map(t_data *data);
int		validate_top_bottom(t_data *data);
int		validate_sides(t_data *data);
int		validate_interior(t_data *data);
void	get_above_below(t_data *data, int line_numb, int *above, int *below);
int		get_map_height(t_list *head);

#endif
