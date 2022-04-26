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
	if (key_nb == MAIN_PAD_PLUS)
	{
		mlx->scale += 2;
		prop = mlx->scale / old;
		mlx->scale_z *= prop;
	}
	if (key_nb == MAIN_PAD_MINUS && mlx->scale > 2)
	{
		mlx->scale -= 2;
		prop = mlx->scale / old;
		mlx->scale_z *= prop;
	}
	if (key_nb == MAIN_PAD_9)
		mlx->scale_z += 1;
	if (key_nb == MAIN_PAD_8)
		mlx->scale_z -= 1;
}

void	style_key(int key_nb, t_mlx *mlx)
{
	if (key_nb == MAIN_PAD_1)
		mlx->color_style = 1;
	if (key_nb == MAIN_PAD_2)
		mlx->color_style = 2;
	if (key_nb == MAIN_PAD_3)
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
	if (key_nb == KEY_ESC)
		esc_key(mlx);
	if (key_nb == KEY_O)
	{
		mlx->offset_x = mlx->width * mlx->scale / 2 + 300;
		mlx->offset_y = mlx->height * mlx->scale / 2 + 150;
	}
	if (key_nb == KEY_E || key_nb == KEY_D || key_nb == KEY_F
		|| key_nb == KEY_R || key_nb == KEY_T || key_nb == KEY_G
		|| key_nb == KEY_I || key_nb == KEY_P)
		projection_rotation(key_nb, mlx);
	if (key_nb == MAIN_PAD_PLUS || key_nb == MAIN_PAD_MINUS
		|| key_nb == MAIN_PAD_8 || key_nb == MAIN_PAD_9)
		zoom_key(key_nb, mlx);
	if (key_nb == MAIN_PAD_1 || key_nb == MAIN_PAD_2 || key_nb == MAIN_PAD_3)
		style_key(key_nb, mlx);
	draw_img(mlx);
	return (0);
}
