/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:31:28 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/02 12:35:31 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (1);
	if (s1 && s2)
	{
		if (ft_strcmp(s1, s2) == 0)
			return (1);
	}
	return (0);
}
