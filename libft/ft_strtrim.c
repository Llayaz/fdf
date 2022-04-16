/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:18:10 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/12 16:20:13 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_white_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

char	*ft_strtrim(const char *s)
{
	int		start;
	int		len;
	int		i;
	char	*new_str;

	if (!s)
		return (NULL);
	start = -1;
	len = (int)ft_strlen(s);
	i = 0;
	while (ft_is_white_space(s[len - 1]) == 1)
		--len;
	while (ft_is_white_space(s[++start]) == 1)
		--len;
	if (len < 0)
		len = 0;
	new_str = ft_strnew((size_t)len);
	if (!new_str)
		return (NULL);
	while (i < len)
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}
