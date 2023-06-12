/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:18 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/20 17:28:56 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lencount(unsigned int n, unsigned int b);

int	ft_printhex(const char *base, unsigned int b, unsigned int n)
{
	char	*str;
	int		aux;
	int		len;

	aux = 0;
	if (n == 0)
	{
		ft_putstr("0");
		return (1);
	}
	len = ft_lencount(n, b) - 1;
	str = calloc(len + 2, sizeof (char));
	if (!str)
		return (0);
	while (n > 0)
	{
		str[len] = base[n % b];
		n = n / b;
		len--;
		aux++;
	}
	ft_putstr(str);
	free(str);
	return (aux);
}

static int	ft_lencount(unsigned int n, unsigned int b)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / b;
		len++;
	}
	return (len);
}
