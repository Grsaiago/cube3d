/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:12:34 by gsaiago           #+#    #+#             */
/*   Updated: 2023/04/07 14:55:37 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	if (!c)
		return (0);
	i = 0;
	while (c[i])
		i++;
	return (i);
}

/*
int main (void)
{
	char	c[] = "Esse vetor aqui";
	
	printf ("A função strlen retorna: %lu\n", strlen(c));
	printf ("A função ft_strlen retorna: %u\n", ft_strlen(c));
}
*/
