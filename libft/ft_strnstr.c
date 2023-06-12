/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:13:30 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/04 17:13:48 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ndle;
	char	*hay;
	size_t	i;
	size_t	j;

	ndle = (char *)needle;
	hay = (char *)haystack;
	i = -1;
	if (!ndle[0])
		return (hay);
	while (++i < len && hay[i])
	{
		j = 0;
		while (hay[i + j] == ndle[j] && (i + j) < len)
		{
			if (needle[j + 1] == 0)
				return (hay + i);
			j++;
		}
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str1[] = "Essa string aqui";
	char	str2[] = "stringo";

	printf("Haystack > %s\n", str1);
	printf("Needle > %s\n", str2);
	printf("Original > %s\n", strnstr(str1, str2, 20));
	printf("Ft > %s\n", ft_strnstr(str1, str2, 20));
}
*/
