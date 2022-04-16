/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:23:09 by ncsomori          #+#    #+#             */
/*   Updated: 2021/10/28 15:48:18 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	i;
	char	*str_cpy;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		++len;
	str_cpy = ft_strnew(len);
	if (!str_cpy)
		return (NULL);
	while (src[i] != '\0')
	{
		str_cpy[i] = src[i];
		++i;
	}
	return (str_cpy);
}
