/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:25:55 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/08 09:58:18 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ptr = (char *)s + i;
		i++;
	}
	if (s[i] == c)
		ptr = (char *)s + i;
	return (ptr);
}
