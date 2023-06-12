/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:22:48 by gsaiago           #+#    #+#             */
/*   Updated: 2022/11/22 21:15:11 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_free(char *s1, char *s2, int flag);
static char	*join_str(char *s1, char *s2);

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	char	*str;

	str = join_str(s1, s2);
	if (!str)
		return (NULL);
	if (flag)
		check_free(s1, s2, flag);
	return (str);
}

static char	*join_str(char *s1, char *s2)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	if (!s1)
		return (ft_strdup(s2, 0));
	if (!s2)
		return (ft_strdup(s1, 0));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	count = 0;
	str = ft_calloc((i + j + 1), 1);
	if (str == NULL)
		return (NULL);
	while (count < i)
	{
		str[count] = s1[count];
		count++;
	}
	while (--j >= 0)
		str[count + j] = s2[j];
	return (str);
}

static void	check_free(char *s1, char *s2, int flag)
{
	if (flag == 1)
	{
		if (s1)
			free(s1);
	}
	else if (flag == 2)
	{
		if (s2)
			free(s1);
	}
	else if (flag == 3)
	{
		if (s1)
			free(s1);
		if (s2)
			free(s1);
	}
	return ;
}
/*
int	main (void)
{
	const char	str1[] = "Essa string aqui ta incompleta";
	const char	str2[] = "a não ser que seja com essa";

	printf("s1 > %s\n", str1); 
	printf("s2 > %s\n", str2); 
	printf("join > %s\n", ft_strjoin(str1, str2)); 
}
*/
