/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:00:05 by gsaiago           #+#    #+#             */
/*   Updated: 2022/05/31 11:50:21 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	else
		return (0);
}

/*
int main	(void)
{
	printf("A função isdigit retorna: %d\n", isdigit('4'));
	printf("A função ft_isdigit retorna: %d\n", ft_isdigit('4'));
}
*/
