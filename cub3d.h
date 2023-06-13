/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:36:14 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/13 19:13:36 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_data
{
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	unsigned int	F;
	unsigned int	C;
} t_data;

/* info validation */
int	cb_get_no(t_list *head, t_data *data);
int	cb_get_so(t_list *head, t_data *data);
int	cb_get_we(t_list *head, t_data *data);
int	cb_get_ea(t_list *head, t_data *data);
int	cb_get_map(t_list *head, t_data *data);
int	cb_get_f(t_list *head, t_data *data);
int	cb_get_c(t_list *head, t_data *data);
int	cb_get_params(t_list *lst, t_data *data);

#endif
