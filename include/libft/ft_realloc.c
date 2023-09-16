/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:45:13 by gsaiago           #+#    #+#             */
/*   Updated: 2023/06/12 17:50:03 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *oldptr, size_t new_size)
{
	void	*ptr;

	ptr = malloc(new_size);
	if (!ptr)
		return (NULL);
	if (oldptr)
	{
		if (new_size > 0)
			ft_memcpy(ptr, oldptr, new_size);
		free(oldptr);
	}
	return (ptr);
}
