/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:36:14 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/14 15:31:12 by gsaiago          ###   ########.fr       */
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
} t_rgb;


typedef struct s_data
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	t_rgb	F;
	t_rgb	C;
} t_data;

/* info validation */
int	cb_load_no(t_list *head, t_data *data);
int	cb_load_so(t_list *head, t_data *data);
int	cb_load_we(t_list *head, t_data *data);
int	cb_load_ea(t_list *head, t_data *data);
int	cb_load_map(t_list *head, t_data *data);
int	cb_load_f(t_list *head, t_data *data);
int	cb_load_c(t_list *head, t_data *data);
int	cb_load_params(t_list *lst, t_data *data);
int	mat_to_rgb(char **mat, t_rgb *rgb);

#endif
