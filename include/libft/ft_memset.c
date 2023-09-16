/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:01:19 by gsaiago           #+#    #+#             */
/*   Updated: 2022/05/31 11:42:35 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;

	ch = (unsigned char) c;
	i = -1;
	while (++i < len)
		((char *)dest)[i] = ch;
	return (dest);
}

/*
int main (void)
{
	char	memdest[] = "Esse vetor aqui em mermao";
	char	ftmemdest[]  = "Esse vetor aqui em mermao";
}
*/
