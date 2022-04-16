/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:38:49 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/02 12:16:55 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		is_neg;
	long	num;

	i = 0;
	is_neg = 1;
	num = 0;
	while (ft_isspace(str[i]) == 1 && str[i] != '\0')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_neg = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = 10 * num + (str[i] - '0');
		++i;
	}
	return ((int)num * is_neg);
}
