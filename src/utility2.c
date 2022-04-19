/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:14:04 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/19 09:14:06 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	kill_array(char **arr)
{
	ft_free_array(arr);
	perror("Error");
	exit(1);
}

void	write_instruct(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 25, 25, 0xffffff, "How to use");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 25, 50, 0xffffff, "ESC to quit");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 25, 75, 0xffffff,
		"P : change projection");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 25, 100, 0xffffff,
		"Use arrows to move");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 25, 125, 0xffffff,
		"+ - : change scale");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 25, 150, 0xffffff,
		"8 9 : change z scale");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 25, 175, 0xffffff,
		", . : change angle");
}
