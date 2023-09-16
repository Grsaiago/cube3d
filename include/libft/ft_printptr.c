/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:18 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/20 17:29:12 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lencount(unsigned long n);

unsigned int	ft_printptr(const char *base, void *ptr)
{
	char			*str;
	int				aux;
	int				len;
	unsigned long	n;

	n = (unsigned long)ptr;
	if (n == 0)
		return (write(1, "0x0", 3));
	len = ft_lencount(n) - 1;
	str = ft_calloc(len + 2, sizeof (char));
	if (!str)
		return (0);
	aux = write(1, "0x", 2);
	while (n > 0)
	{
		str[len] = base[n % 16];
		n = n / 16;
		len--;
	}
	aux += ft_putstr(str);
	free(str);
	return (aux);
}

static int	ft_lencount(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
