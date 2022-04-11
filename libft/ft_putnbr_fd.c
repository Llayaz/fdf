/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:40:07 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/02 10:42:23 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs_val;

	if (n < 0)
	{
		abs_val = -(unsigned int)n;
		write(fd, "-", 1);
	}
	else
		abs_val = (unsigned int)n;
	if (abs_val < 10)
	{
		ft_putchar_fd((char)abs_val + '0', fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(abs_val / 10, fd);
		ft_putchar_fd(abs_val % 10 + '0', fd);
		return ;
	}
}
