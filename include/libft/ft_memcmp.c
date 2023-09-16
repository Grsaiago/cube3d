/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:00:17 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/15 21:08:51 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*str1;
	const char	*str2;

	str1 = s1;
	str2 = s2;
	i = -1;
	if (n == 0)
		return (0);
	while (++i < n)
		if (str1[i] != str2[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
	return (0);
}

/*
int	main(void)
{
	char	str1[] = "Essa aqui";
	char	str2[] = "Essa aqui";

	printf("str1 > %s\n", str1);
	printf("str2 > %s\n", str2);
	printf("memcmp > %d\n", memcmp(str1, str2, 50));
	printf("ft_memcmp > %d\n", ft_memcmp(str1, str2, 50));
}
*/
