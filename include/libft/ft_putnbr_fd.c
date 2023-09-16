/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:07:31 by gsaiago           #+#    #+#             */
/*   Updated: 2022/11/17 17:12:37 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	char			nb;
	unsigned long	n;

	if (nbr < 0)
	{
		n = (unsigned long) nbr * -1;
		write (fd, "-", 1);
	}
	else
		n = nbr;
	if (n < 10)
	{
		nb = n + 48;
		write (fd, &nb, 1);
		return ;
	}
	else
		ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd (n % 10, fd);
}

/*
int	main (void)
{
	int	fd;
	int	n;

	fd = 1;
	n = -2147483648;

	ft_putnbr_fd(n, fd);
}
*/
