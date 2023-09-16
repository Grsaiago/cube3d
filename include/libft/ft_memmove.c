/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:00:59 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/01 15:04:38 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst,	const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src == dst || len == 0)
		return ((char *)dst);
	if (src > dst)
	{
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	if (src < dst)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	return ((char *)dst);
}

/*
int main (void)
{
	char	sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char	sResult1[] = {67, 68, 67, 68, 69, 0, 45};

	memmove(sResult + 1, sResult, 2);
	ft_memmove(sResult1 + 1, sResult1, 2);
	printf("memmove > %s\n",sResult); 
	printf("ft_memmove > %s\n",sResult1); 
}
*/
