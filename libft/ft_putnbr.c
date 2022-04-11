/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:40:25 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/02 10:24:35 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	abs_val;

	if (n < 0)
	{
		abs_val = -(unsigned int)n;
		ft_putchar('-');
	}
	else
		abs_val = (unsigned int)n;
	if (abs_val < 10)
	{
		ft_putchar((char)abs_val + '0');
		return ;
	}
	else
	{
		ft_putnbr(abs_val / 10);
		ft_putchar(abs_val % 10 + '0');
		return ;
	}
}
