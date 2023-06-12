/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:59:12 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/15 15:20:57 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lencount(int n);

char	*ft_itoa(int n)
{
	int		len;
	char	*itoa;

	if (n == -2147483648)
		return (ft_strdup("-2147483648", 0));
	if (n == 0)
		return (ft_strdup("0", 0));
	len = ft_lencount(n);
	itoa = ft_calloc(len + 2, 1);
	if (!itoa)
		return (NULL);
	if (n > 0)
		len--;
	else
	{
		itoa[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		itoa[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (itoa);
}

static int	ft_lencount(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/*
int	main (void)
{
	int	i;

	i = 2147483647;
	printf("int > %d\n", i);
	printf("ft_itoa > %s\n", ft_itoa(i));
}
*/
