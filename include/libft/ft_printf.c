/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:02:12 by gsaiago           #+#    #+#             */
/*   Updated: 2022/11/17 17:12:10 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_params(const char *s, int aux, va_list vlist);

int	ft_printf(const char *s, ...)
{
	va_list		vlist;
	long int	aux;

	aux = ft_strlen(s);
	va_start(vlist, s);
	while (*s)
	{
		while (*s == '%')
		{
			s++;
			aux = ft_params(s, aux, vlist);
			s++;
		}
		if (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
	va_end(vlist);
	return (aux);
}

static int	ft_params(const char *s, int aux, va_list vlist)
{
	if (*s == 'c')
		aux += ft_putchar(va_arg(vlist, int)) - 2;
	else if (*s == 's')
		aux += ft_putstr(va_arg(vlist, char *)) - 2;
	else if (*s == 'i' || *s == 'd')
		aux += ft_putnbr(va_arg(vlist, int)) - 2;
	else if (*s == '%')
		aux += write(1, "%", 1) - 2;
	else if (*s == 'u')
		aux += ft_printhex("0123456789", 10, va_arg(vlist, unsigned int)) - 2;
	else if (*s == 'x')
		aux += ft_printhex("0123456789abcdef", 16,
				va_arg(vlist, unsigned int)) - 2;
	else if (*s == 'X')
		aux += ft_printhex("0123456789ABCDEF", 16,
				va_arg(vlist, unsigned int)) - 2;
	else if (*s == 'p')
		aux += ft_printptr("0123456789abcdef", va_arg(vlist, void *)) - 2;
	return (aux);
}
