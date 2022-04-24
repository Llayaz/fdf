/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:04:16 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/23 17:04:19 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_key(int key_nb, t_mlx *mlx)
{
	if (key_nb == 65363)
		mlx->offset_x += 20;
	if (key_nb == 65361)
		mlx->offset_x -= 20;
	if (key_nb == 65362)
		mlx->offset_y -= 20;
	if (key_nb == 65364)
		mlx->offset_y += 20;
}

void	projection_rotation(int key_nb, t_mlx *mlx)
{
	if (key_nb == 114)
		mlx->alpha += 0.05;
	if (key_nb == 101)
		mlx->beta += 0.05;
	if (key_nb == 116)
		mlx->gamma += 0.05;
	if (key_nb == 112)
	{
		mlx->is_iso = 0;
		mlx->alpha = 0;
		mlx->beta = 0;
		mlx->gamma = 0;
	}
	if (key_nb == 105)
		mlx->is_iso = 1;
}

int	key_pressed(int key_nb, t_mlx *mlx)
{
	printf("key pressed\n");
	ft_putnbr(key_nb);
	if (key_nb == 65363 || key_nb == 65361 || key_nb == 65362
		|| key_nb == 65364)
		move_key(key_nb, mlx);
	draw_img(mlx);
	return (0);
}
