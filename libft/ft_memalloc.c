/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 08:54:13 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/12 08:55:59 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ret;

	ret = (unsigned char *)malloc(size);
	if (!ret)
		return (NULL);
	while (size)
	{
		ret[--size] = 0;
	}
	return ((void *)ret);
}
