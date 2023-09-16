/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:11:47 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/15 21:13:35 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len;

	i = -1;
	len = 0;
	while (src[len])
		len++;
	if (dstsize <= 0)
		return (len);
	while (src[++i] && (i < dstsize - 1))
		dst[i] = src[i];
	dst[i] = 0;
	return (len);
}

/*
int main (void)
{
	const char	src[] = "123456789";
	char		dest[] = "987654321 dest";
	char		destft[] = "987654321 destft";

	printf("original > %s\n", src);
	printf("dest > %lu\n", strlcpy(dest, src, 42));
	printf("dest > %s\n", dest);
	printf("destft > %lu\n", ft_strlcpy(destft, src, 42));
	printf("destft > %s\n", destft);
}
*/
