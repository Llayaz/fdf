/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:27:01 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/15 12:27:03 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_data *new, t_mlx *mlx)
{
	double	y;

	y = new->ay;
	new->ay = y * cos(mlx->alpha) + new->az * sin(mlx->alpha);
	new->az = (float)(-y * sin(mlx->alpha) + new->az * cos(mlx->alpha));
	y = new->by;
	new->by = y * cos(mlx->alpha) + new->bz * sin(mlx->alpha);
	new->bz = (float)(-y * sin(mlx->alpha) + new->bz * cos(mlx->alpha));
}

void	rotate_y(t_data *new, t_mlx *mlx)
{
	double	x;

	x = new->ax;
	new->ax = x * cos(mlx->beta) + new->az * sin(mlx->beta);
	new->az = (float)(-x * sin(mlx->beta) + new->az * cos(mlx->beta));
	x = new->bx;
	new->bx = x * cos(mlx->beta) + new->bz * sin(mlx->beta);
	new->bz = (float)(-x * sin(mlx->beta) + new->bz * cos(mlx->beta));
}

void	rotate_z(t_data *new, t_mlx *mlx)
{
	double	y;
	double	x;

	x = new->ax;
	y = new->ay;
	new->ax = x * cos(mlx->gamma) - y * sin(mlx->gamma);
	new->ay = x * sin(mlx->gamma) + y * cos(mlx->gamma);
	x = new->bx;
	y = new->by;
	new->bx = x * cos(mlx->gamma) - y * sin(mlx->gamma);
	new->by = x * sin(mlx->gamma) + y * cos(mlx->gamma);
}
