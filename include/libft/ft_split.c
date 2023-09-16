/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:22:51 by gsaiago           #+#    #+#             */
/*   Updated: 2023/03/22 23:16:40 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c);
static int		count_word_len(char *str, char c);
static char		**ft_mat(char *str, char c, int words);

char	**ft_split(char *str, char c)
{
	int		words;
	char	**mat;

	if (!str)
		return (NULL);
	words = count_words(str, c);
	mat = ft_mat(str, c, words);
	if (!mat)
		return (NULL);
	return (mat);
}

static size_t	count_words(const char *str, char c)
{
	int	words;

	words = 0;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		words++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (words);
}

static int	count_word_len(char *str, char c)
{
	int	word_len;

	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	return (word_len);
}

static char	**ft_mat(char *str, char c, int words)
{
	int		i;
	char	**mat;

	mat = ft_calloc((words + 1), sizeof(char *));
	if (!mat)
		return (NULL);
	i = -1;
	while (*str && (++i < words))
	{
		while (*str && *str == c)
			str++;
		mat[i] = ft_substr(str, 0, count_word_len(str, c));
		if (!mat[i])
		{
			while (mat[i])
			{
				free(mat[i]);
				i--;
			}
			return (NULL);
		}
		while (*str && *str != c)
			str++;
	}
	return (mat);
}
