/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:06:54 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/28 13:34:23 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strdup(char *s1, int flag)
{
	int		len;
	char	*ptr;

	len = 0;
	while (s1[len])
		len++;
	ptr = ft_valloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (len-- > 0)
		ptr[len] = s1[len];
	if (flag && s1)
		free(s1);
	return (ptr);
}
