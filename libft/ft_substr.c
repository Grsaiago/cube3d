/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:55:50 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/15 17:20:29 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup("", 0));
	if ((start + len) > lens)
		len = lens - start;
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	ft_memmove(str, &((char *)s)[start], len);
	return (str);
}

/*
int	main(void)
{
	char	*s;

	s = ft_substr("lorem ipsum dolor sit amet", 0, 10);

	printf("%s\n", s);
}
*/
