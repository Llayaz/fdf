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

void	zoom_key(int key_nb, t_mlx *mlx)
{
	float	old;
	float	prop;

	old = mlx->scale;
	if (key_nb == 43)
	{
		mlx->scale += 2;
		prop = mlx->scale / old;
		mlx->scale_z *= prop;
	}
	if (key_nb == 45 && mlx->scale > 2)
	{
		mlx->scale -= 2;
		prop = mlx->scale / old;
		mlx->scale_z *= prop;
	}
	if (key_nb == 57)
		mlx->scale_z += 1;
	if (key_nb == 56)
		mlx->scale_z -= 1;
}

void	style_key(int key_nb, t_mlx *mlx)
{
	if (key_nb == 49)
		mlx->color_style = 1;
	if (key_nb == 50)
		mlx->color_style = 2;
	if (key_nb == 51)
		mlx->color_style = 3;
}

void	esc_key(t_mlx *mlx)
{
	clearup(mlx);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
//	system("leaks fdf");
	exit(EXIT_SUCCESS);
}

int	deal_key(int key_nb, t_mlx *mlx)
{
	ft_putnbr(key_nb);
	if (key_nb == 65307)
		esc_key(mlx);
	if (key_nb == 111)
	{
		mlx->offset_x = mlx->win_x / 4 * 3 - (mlx->width * mlx->scale) / 2;
		mlx->offset_y = mlx->win_y / 3 - (mlx->height * mlx->scale) / 2;
	}
	if (key_nb == 101 || key_nb == 114 || key_nb == 116 || key_nb == 112
		|| key_nb == 105)
		projection_rotation(key_nb, mlx);
	if (key_nb == 65363 || key_nb == 65361 || key_nb == 65362
		|| key_nb == 65364)
		move_key(key_nb, mlx);
	if (key_nb == 43 || key_nb == 45 || key_nb == 56 || key_nb == 57)
		zoom_key(key_nb, mlx);
	if (key_nb == 46)
		mlx->angle += 0.1;
	if (key_nb == 44)
		mlx->angle -= 0.1;
	if (key_nb == 49 || key_nb == 50 || key_nb == 51)
		style_key(key_nb, mlx);
	draw_img(mlx);
	return (0);
}
