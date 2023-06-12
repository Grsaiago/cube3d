/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:39 by gsaiago           #+#    #+#             */
/*   Updated: 2023/05/22 12:19:08 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42 
#endif

static char	*get_temp_buff(char *staticbuff, int fd);
static char	*get_return_buff(char *staticbuff);
static char	*get_static_buff(char *staticbuff);

char	*get_next_line(int fd)
{
	static char	*staticbuff;
	char		*returnbuff;

	if (fd < 0)
	{
		if (staticbuff)
			free(staticbuff);
		return (NULL);
	}
	staticbuff = get_temp_buff(staticbuff, fd);
	if (!staticbuff)
		return (NULL);
	returnbuff = get_return_buff(staticbuff);
	staticbuff = get_static_buff(staticbuff);
	return (returnbuff);
}

static char	*get_static_buff(char *staticbuff)
{
	char	*newstatbuff;
	size_t	newlen;
	size_t	statlen;

	if (staticbuff && ft_strchr(staticbuff, '\n'))
	{
		newlen = 0;
		statlen = 0;
		while (staticbuff[statlen] != '\n')
			statlen++;
		statlen++;
		while (staticbuff[statlen + newlen])
			newlen++;
		newstatbuff = ft_calloc(sizeof(char), newlen + 1);
		ft_memmove(newstatbuff, &staticbuff[statlen], newlen);
		free(staticbuff);
		return (newstatbuff);
	}
	else
		free(staticbuff);
	return (NULL);
}

static char	*get_return_buff(char *staticbuff)
{
	char	*returnbuff;
	int		returnlen;

	returnlen = 0;
	while (staticbuff[returnlen] && staticbuff[returnlen] != '\n')
		returnlen++;
	if (staticbuff[returnlen] == '\n')
		returnlen++;
	if (returnlen == 0)
		return (NULL);
	returnbuff = calloc(sizeof(char), returnlen + 1);
	ft_memmove(returnbuff, staticbuff, returnlen);
	return (returnbuff);
}

static char	*get_temp_buff(char *staticbuff, int fd)
{
	char		readbuff[BUFFER_SIZE + 1];
	int			readflag;

	if (staticbuff && ft_strchr(staticbuff, '\n'))
		return (staticbuff);
	while (42)
	{
		readflag = read(fd, readbuff, BUFFER_SIZE);
		if (readflag < 0)
		{
			free(staticbuff);
			return (NULL);
		}
		if (readflag > 0)
		{
			readbuff[readflag] = '\0';
			staticbuff = ft_strjoin(staticbuff, readbuff, 1);
		}
		if (!staticbuff || ft_strchr(staticbuff, '\n') || readflag == 0)
			break ;
	}
	return (staticbuff);
}
