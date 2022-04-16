/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:31:54 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/02 19:50:18 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digit_counter(int n)
{
	int		num;
	size_t	dig;

	num = n;
	if (n < 0)
		dig = 1;
	else
		dig = 0;
	while (num / 10 != 0)
	{
		num = num / 10;
		++dig;
	}
	++dig;
	return (dig);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	dig;
	int		num;

	dig = ft_digit_counter(n);
	str = ft_strnew(dig);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
		num = -n;
	else
		num = n;
	if (!str)
		return (NULL);
	while ((int)dig-- >= 0)
	{
		if (num < 10)
			str[dig] = (char)num + '0';
		else
			str[dig] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
