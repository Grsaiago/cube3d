/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:00:13 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/15 21:08:36 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "Essa string aqui a";

	printf("Str > %s\n", str);
	printf("ft_memchr > %s\n", ((char *) ft_memchr(str, 'a', 4)));
	printf("memchr > %s\n", ((char *) memchr(str, 'a', 4)));
}
*/
