/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:13:04 by gsaiago           #+#    #+#             */
/*   Updated: 2023/04/05 17:09:50 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

/*
int	main(void)
{
//	char	str1[] = "Essa st";
//	char	str2[] = "Essa st";

//	printf("Str 1 > %s\n", str1);
//	printf("Str 2 > %s\n", str2);
	printf("Retorno strncmp > %d\n", strncmp("1234", "1235", 3));
	printf("Retorno ft_strncmp > %d\n",ft_strncmp("1234", "1235", 3));
}
*/
