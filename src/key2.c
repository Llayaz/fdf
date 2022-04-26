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
	if (key_nb == ARROW_RIGHT)
		mlx->offset_x += 10;
	if (key_nb == ARROW_LEFT)
		mlx->offset_x -= 10;
	if (key_nb == ARROW_UP)
		mlx->offset_y -= 10;
	if (key_nb == ARROW_DOWN)
		mlx->offset_y += 10;
}

void	projection_rotation(int key_nb, t_mlx *mlx)
{
	if (key_nb == KEY_E)
		mlx->alpha += 0.05;
	if (key_nb == KEY_D)
		mlx->alpha -= 0.05;
	if (key_nb == KEY_R)
		mlx->beta += 0.05;
	if (key_nb == KEY_F)
		mlx->beta -= 0.05;
	if (key_nb == KEY_T)
		mlx->gamma += 0.05;
	if (key_nb == KEY_G)
		mlx->gamma -= 0.05;
	if (key_nb == KEY_P)
	{
		mlx->is_iso = 0;
		mlx->alpha = 0;
		mlx->beta = 0;
		mlx->gamma = 0;
	}
	if (key_nb == KEY_I)
		mlx->is_iso = 1;
}

int	key_pressed(int key_nb, t_mlx *mlx)
{
	ft_putnbr(key_nb);
	if (key_nb == ARROW_UP || key_nb == ARROW_DOWN || key_nb == ARROW_LEFT
		|| key_nb == ARROW_RIGHT)
		move_key(key_nb, mlx);
	draw_img(mlx);
	return (0);
}
