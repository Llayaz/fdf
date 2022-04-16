/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:25:49 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/15 18:25:54 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lerp_int(int start, int end, double percentage)
{
	if (start == end)
		return (start);
	return ((int)((1 - percentage) * start + percentage * end));
}
