/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:44:16 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/08 11:49:40 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*str;
	unsigned char	*new;
	size_t			i;

	str = (const char *)src;
	new = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)str + i) == (unsigned char)c)
		{
			*(new + i) = *((unsigned char *)str + i);
			return ((unsigned char *)dst + i + 1);
		}
		*(new + i) = *((unsigned char *)str + i);
		i++;
	}
	return (NULL);
}
