/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:38:38 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/20 17:29:40 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writenbr(int nbr);
static int	ft_lencount(long int n);

int	ft_putnbr(int nbr)
{
	ft_writenbr(nbr);
	return (ft_lencount(nbr));
}

static void	ft_writenbr(int nbr)
{
	char	nb;
	long	n;

	if (nbr < 0)
	{
		n = (long) nbr * -1;
		write (1, "-", 1);
	}
	else
		n = (long) nbr;
	if (n < 10 && n >= 0)
	{
		nb = n + 48;
		write (1, &nb, 1);
		return ;
	}
	else
		ft_putnbr(n / 10);
	ft_putnbr(n % 10);
	return ;
}

static int	ft_lencount(long int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else if (n == 0)
		len = 1;
	else
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
