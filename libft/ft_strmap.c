/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:51:32 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/12 13:52:21 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*newstr;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	newstr = ft_strnew(len);
	if (newstr == NULL)
		return (0);
	while (s[i] != '\0')
	{
		newstr[i] = f(s[i]);
		++i;
	}
	newstr[i] = '\0';
	return (newstr);
}
