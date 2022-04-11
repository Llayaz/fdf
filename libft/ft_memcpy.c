/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:58:13 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/06 09:59:30 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dstr;
	const unsigned char	*sstr;

	i = 0;
	dstr = (unsigned char *)dest;
	sstr = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		dstr[i] = sstr[i];
		i++;
	}
	return (dest);
}
