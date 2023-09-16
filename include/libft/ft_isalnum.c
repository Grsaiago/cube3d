/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:56:41 by gsaiago           #+#    #+#             */
/*   Updated: 2022/05/31 11:52:11 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (c);
	else
		return (0);
}

/*
int main (void)
{
	printf("A função isalnum retorna: %d\n", isalnum('c'));
	printf("A função ft_isalnum retorna: %d\n", ft_isalnum('c'));
}
*/
