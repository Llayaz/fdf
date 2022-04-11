/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:04:35 by ncsomori          #+#    #+#             */
/*   Updated: 2022/03/16 15:04:41 by ncsomori         ###   ########.fr       */
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

void	zoom_key(int key_nb, t_mlx *mlx)
{
	if (key_nb == 43)
		mlx->scale += 2;
	if (key_nb == 45 && mlx->scale > 2)
		mlx->scale -= 2;
	if (key_nb == 57)
		mlx->scale_z += 1;
	if (key_nb == 56)
		mlx->scale_z -= 1;
}

int	deal_key(int key_nb, t_mlx *mlx)
{
	ft_putnbr(key_nb);
	if (key_nb == 65307)
	{
		clearup(mlx);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		system("leaks fdf");
		exit(EXIT_SUCCESS);
	}
	if (key_nb == 105)
	{
		mlx->is_iso = (mlx->is_iso == 1) ? 0 : 1;
/*		if (mlx->is_iso == 0)
			mlx->is_iso = 1;
		else
			mlx->is_iso = 0;*/
	}
	if ( key_nb == 65363 || key_nb == 65361 || key_nb == 65362
		|| key_nb == 65364)
		move_key(key_nb, mlx);
	if (key_nb == 43 || key_nb == 45 || key_nb == 56 || key_nb == 57)
		zoom_key(key_nb, mlx);
	if (key_nb == 46)
		mlx->angle += 0.1;
	if (key_nb == 44)
		mlx->angle -= 0.1;
	draw_img(mlx);
	return (0);
}
