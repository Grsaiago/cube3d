/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:33:58 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/13 16:40:50 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static t_list		*ft_file_to_lst(int fd, int flags);
static unsigned int	ft_get_str_size(t_list *node);
static char			*ft_lst_to_str(t_list *node);
static char			**ft_aux_lst_to_mat(t_list *node);

void	*ft_read_file(int fd, int flags)
{
	union u_read	u;

	if (fd < 0)
		return (NULL);
	u.lst = ft_file_to_lst(fd, flags);
	if (!u.lst)
		return (NULL);
	if (flags & FT_LST)
		return (u.str);
	else if (flags & FT_STR)
		return (ft_lst_to_str(u.lst));
	else if (flags & FT_MAT)
		return (ft_aux_lst_to_mat(u.lst));
	ft_lstclear(&u.lst, free);
	return (NULL);
}

static char	*ft_lst_to_str(t_list *node)
{
	unsigned int	size;
	t_list			*aux;
	char			*str;
	int				i;

	size = ft_get_str_size(node);
	if (node == 0)
		return (NULL);
	str = ft_calloc(size + 1, sizeof(char));
	i = 0;
	while (node)
	{
		aux = node;
		ft_memmove(&str[i], node->content, ft_strlen(node->content));
		i += ft_strlen(node->content);
		node = node->next;
		free(aux->content);
		free(aux);
	}
	return (str);
}

static unsigned int	ft_get_str_size(t_list *node)
{
	unsigned int	i;

	i = 0;
	while (node)
	{
		i += ft_strlen(node->content);
		node = node->next;
	}
	return (i);
}

static t_list	*ft_file_to_lst(int fd, int flags)
{
	t_list	*node;
	t_list	*head;
	char	*line;
	char	*aux;

	if (fd < 0)
		return (NULL);
	head = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if ((flags & FT_NON) && (line[ft_strlen(line) - 1] == '\n'))
		{
			aux = line;
			line = ft_substr(line, 0, ft_strlen(line) - 1);
			free(aux);
		}
		node = ft_lstnew(line);
		if (!node)
			return (ft_lstclear(&head, free), NULL);
		ft_lstadd_back(&head, node);
		line = get_next_line(fd);
	}
	return (head);
}

static char	**ft_aux_lst_to_mat(t_list *node)
{
	char	**mat;
	t_list	*aux;
	int		i;
	int		listsize;

	if (!node)
		return (NULL);
	listsize = ft_lstsize(node);
	if (listsize <= 0)
		return (NULL);
	mat = ft_calloc(listsize + 1, sizeof(char *));
	if (!mat)
		return (NULL);
	i = 0;
	while (node)
	{
		aux = node;
		mat[i] = node->content;
		node = node->next;
		free(aux);
		i++;
	}
	return (mat);
}

/*
int main(void)
{

	int 	fd;
	char	**str;

	fd = open("./oie", O_RDWR);
	str = ft_read_file(fd, FT_MAT | FT_N);
	ft_free_mat(str);
	close(fd);
	return (0);
}
*/
