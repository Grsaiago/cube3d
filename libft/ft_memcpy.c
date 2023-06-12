/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:52:51 by gsaiago           #+#    #+#             */
/*   Updated: 2022/11/17 17:11:50 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	const char		*srcc;
	char			*destc;

	destc = (char *)dest;
	srcc = (const char *)src;
	if (!destc && !srcc)
		return (NULL);
	while (len--)
		*destc++ = *srcc++;
	return (dest);
}

/*
int	main(void)
{
	char	src[] = "cinco";
	char	src1[] = "cinco";
	printf("str src:\n%s\n", src);
	printf("O retorno da ft é > %s\n", ((char *)ft_memcpy(src + 1,src, 2)));
	printf("O retorno da original é > %s\n",((char *)memmove(src1 + 1,src1, 2)));
}
*/
