/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:25:04 by ncsomori          #+#    #+#             */
/*   Updated: 2022/03/15 18:25:10 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(const char *s, char c)
{
	size_t	j;
	size_t	word;

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
