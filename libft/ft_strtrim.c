/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:36:00 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/14 18:44:49 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str;

	len = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1) - 1;
	while (s1[len] && ft_strchr(set, s1[len]) && len >= 0)
			len--;
	len++;
	str = ft_calloc(len + 1, 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy((void *) str, (const void *) s1, len);
	return (str);
}

/*
int	main(void)	
{
	char	str1[] = "123123123123123Essa string aqui123123123123";
	char	set[] = "123";

	printf("str > %s\n", str1);
	printf("set > %s\n", set);
	printf("trim > %s\n", ft_strtrim(str1, set));
}
*/
