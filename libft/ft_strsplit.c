/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:54:40 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/23 13:55:17 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(const char *s, char c)
{
	size_t		j;
	size_t		word;

	j = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			if (j == 0)
				word++;
			else if (s[j - 1] == c)
				word++;
		}
		j++;
	}
	return (word);
}

static size_t	ft_word_len(const char *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i + len] != c && s[i + len] != '\0')
		++len;
	return (len);
}

static void	*ft_free_arr(char **arr, int j)
{
	while (--j >= 0)
		free(arr[j]);
	free(arr);
	return (NULL);
}

static char	**ft_make_arr(const char *s, char **arr, char c)
{
	size_t	i;
	int		j;
	size_t	len;

	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		len = 0;
		if (s[i] != c)
		{
			len = ft_word_len(s, c, i);
			arr[++j] = ft_strsub(s, (unsigned int)i, len);
			if (!arr[j])
				return (ft_free_arr(arr, j));
		}
		i = i + len;
		if (s[i] != '\0')
			++i;
	}
	arr[++j] = NULL;
	return (arr);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	arr = ft_make_arr(s, arr, c);
	if (!arr)
		return (NULL);
	return (arr);
}
