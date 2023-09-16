/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:42:59 by gsaiago           #+#    #+#             */
/*   Updated: 2022/11/22 18:45:01 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s1, int n, int flag)
{
	int		len;
	char	*ptr;

	len = 0;
	while (s1[len] && len < n)
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
