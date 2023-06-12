/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:06:54 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/09 18:04:51 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1, int flag)
{
	int		len;
	char	*ptr;

	len = 0;
	while (s1[len])
		len++;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = 0;
	while (len-- > 0)
		ptr[len] = s1[len];
	if (flag && s1)
		free(s1);
	return (ptr);
}

/*
int	main (void)
{
	char	str[] = "Essa string aqui";

	printf("A str original > %s\n", str);
	printf("A func ft > %s\n", strdup((const char *)str));
	printf("A func original > %s\n", ft_strdup((const char *)str));
}
*/
