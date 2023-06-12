/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:00:09 by gsaiago           #+#    #+#             */
/*   Updated: 2022/05/31 11:49:55 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (c);
	else
		return (0);
}

/*
int main (void)
{
	printf ("A função isprint retorna: %d\n", isprint(100));
	printf ("A função ft_isprint retorna: %d\n", ft_isprint(100));
}
*/
