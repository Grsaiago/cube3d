/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:39:14 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/20 17:50:51 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_pow(size_t base, size_t exp)
{
	if (!exp)
		return (1);
	else if (!base)
		return (0);
	if (!exp)
		return (1);
	else
		return (base * ft_pow(base, exp - 1));
}
