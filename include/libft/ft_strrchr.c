/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:13:54 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/09 18:40:24 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		len;

	len = 0;
	ch = ((char) c);
	while (s[len])
		len++;
	while (len >= 0)
	{
		if (s[len] == ch)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}

/*
int main (void)
{
	char	str[] = "";
	printf("String total> %s\n", str);
	printf("func original> %s\n", strrchr(str, 65));
	printf("func ft> %s\n", ft_strrchr(str, 65));
}
*/
