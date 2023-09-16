/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:07:54 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/15 17:02:01 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;

	i = 0;
	lensrc = 0;
	lendst = 0;
	while (src[lensrc])
		lensrc++;
	while (dst[lendst] && lendst < dstsize)
		lendst++;
	if (dstsize <= lendst)
		return (lensrc + dstsize);
	while ((lendst + i + 1) < dstsize && src[i])
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[i + lendst] = 0;
	return (lendst + lensrc);
}
