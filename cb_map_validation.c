/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:55:49 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/26 14:16:21 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int		cb_validate_map(t_data *data);
int		cb_validate_top_bottom(t_data *data);
int		cb_validate_sides(t_data *data);
int		cb_validate_interior(t_data *data);
void	cb_get_above_below(t_data *data, int line_numb, int *above, int *below);
static int	cb_player_p(t_data *data, const char c);

/* A validação agora tá indo char por char e rodanddo a cb_validate_interior..
 * Essa validate interior sempre recalcula above e below,
 * seria mais inteligente chamar uma função que faz isso no final de um while
 * e dentro do while, caso o caracter seja 0 ela faz aquela checagem que
 * o gguedes falou.
 * Melhor fazer isso pra parte de dentro do mapa e a parte de cima e debaixo 
 * só faz um if (strchr("1 ", line[i] == NULL)){return (erro)}else{i++};
 */

int	cb_validate_map(t_data *data)
{

	if (cb_validate_top_bottom(data))
		return (1);
	else if (cb_validate_sides(data))
		return (1);
	else if (cb_validate_interior(data))
		return (1);
	return (0);
	
}

int	cb_validate_top_bottom(t_data *data)
{
	char	*line;

	line = data->map[0];
	while (*line)
	{
		if (ft_strchr("1 \t\r", *line) == NULL)
			return (perror("Error!\nInvalid char at map top"), 1);
		line++;
	}
	line = data->map[data->map_height - 1];
	while (*line)
	{
		if (ft_strchr("1 \t\r", *line) == NULL)
			return (perror("Error!\nInvalid char at map bottom"), 1);
		line++;
	}
	return (0);
}

int	cb_validate_sides(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = data->map[0];
	while (line)
	{
		while (ft_isspace(*line))
		   line++;
		if ((*line != '1') || (line[ft_strlen(line) - 1] != '1'))
			return (perror("Error!\nInvalid char in some side"), 1);
		i++;
		line = data->map[i];
	}
	return (0);
}

int	cb_validate_interior(t_data *data)
{
	int		line_numb;
	char	*line;
	int		above;
	int		below;
	int		i;

	line_numb = 1;
	line = data->map[1];
	while (line && line_numb < data->map_height)
	{
		cb_get_above_below(data, line_numb, &above, &below);
		i = 0;
		while (line[++i] && (i < (int)ft_strlen(line) - 1))
		{
			if (line[i] == '0' && (i > above || i > below
				|| data->map[line_numb - 1][i] == ' '
				|| data->map[line_numb + 1][i] == ' '
				|| line[i - 1] == ' ' || line[i + 1] == ' '))
				return (perror("Error!\nNonvalid '0' placement"), 1);
			else if (ft_strchr("NSWE", line[i]) && cb_player_p(data, line[i]))
				return (1);
		}
		line_numb++;
		line = data->map[line_numb];
	}
	return (0);
}

void	cb_get_above_below(t_data *data, int line_numb, int *above, int *below)
{
	if (line_numb == 0)
		*above = 0;
	else
		*above = ft_strlen(data->map[line_numb - 1]);
	if (line_numb == data->map_height)
		*below = 0;
	else
		*below = ft_strlen(data->map[line_numb + 1]);
	return ;
}

static int	cb_player_p(t_data *data, const char c)
{
	if (data->spawn_dir)
		return (perror("Error!\nPlayer spawn double definition"), 1);
	data->spawn_dir = c;
	return (0);
}
