/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:37:09 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/15 17:25:07 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = -1;
	str = ft_calloc(ft_strlen(s) + 1, sizeof (char));
	if (str == NULL)
		return (NULL);
	while (s[++i])
		str[i] = (*f)(i, s[i]);
	return (str);
}
