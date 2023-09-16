/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:56:17 by gsaiago           #+#    #+#             */
/*   Updated: 2022/05/31 11:57:11 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
	{
		((char *)b)[i] = 0;
	}
}

/*
void ft_putchar (void *ptr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		write (1, &ptr[i], 1);
		i++;
	}
}

int main (void)
{
	char	str[] = "Isso aqui é uma string que passou pelo bzero";
	char	str2[] = "Isso aqui é uma string que passou pelo ft_bzero";
	
	bzero (str, 5);
	ft_bzero (str2, 5);
	ft_putchar(str, 7);
	ft_putchar(str2, 7);
}
*/
