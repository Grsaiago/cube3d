/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:01:34 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/09 19:10:42 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		len;
	int		i;

	i = 0;
	len = 1 + ft_strlen(s);
	ch = ((char) c);
	while (i < len)
	{
		if (*s == ch)
			return ((char *) s);
		s++;
		i++;
	}
	return (NULL);
}

/*
int main (void)
{
	char	str[] = "Essa string aqui o a e i o u";
	printf("String total> %s\n", str);
	printf("func original> %s\n", strchr(str, 'a'));
	printf("func ft> %s\n", ft_strchr(str, 'a'));
}
*/
