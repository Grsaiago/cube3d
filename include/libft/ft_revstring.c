/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:54:53 by gsaiago           #+#    #+#             */
/*   Updated: 2023/05/10 20:19:12 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstring(char *str)
{
	int	len;
	int	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		if (str[i] == str[len - i - 1])
		{
			i++;
			continue ;
		}
		str[i] ^= str[len - i - 1];
		str[len - i - 1] ^= str[i];
		str[i] ^= str[len - i - 1];
		i++;
	}
	return (str);
}
