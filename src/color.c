/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:07:16 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/11 11:07:18 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	return (placement / distance);
}

void	style_2(t_matrix *a, t_matrix *b, t_data *new)
{
	if (a->z == 0 && b->z == 0)
	{
		new->a_color = 0x145277;
		new->b_color = 0x145277;
	}
	if (a->z != 0 && b->z != 0)
	{
		new->a_color = 0x83d0cb;
		new->b_color = 0x83d0cb;
	}
	if (a->z != 0 && b->z == 0)
	{
		new->a_color = 0x83d0cb;
		new->b_color = 0x145277;
	}
	if (b->z != 0 && a->z == 0)
	{
		new->b_color = 0x83d0cb;
		new->a_color = 0x145277;
	}
	new->color = new->a_color;
}

void	style_3(t_matrix *a, t_matrix *b, t_data *new, t_mlx *mlx)
{
	double	percentage;

	percentage = percent(mlx->min_z, mlx->max_z, a->z);
	if (percentage < 0.35)
		new->a_color = 0x074170;
	else if (percentage < 0.65)
		new->a_color = 0x7e9012;
	else
		new->a_color = 0xfff708;
	percentage = percent(mlx->min_z, mlx->max_z, b->z);
	if (percentage < 0.35)
		new->b_color = 0x074170;
	else if (percentage < 0.65)
		new->b_color = 0x7e9012;
	else
		new->b_color = 0xfff708;
	new->color = new->a_color;
}

/*
** style 1 : parsed color from map + white is no color was given
** style 2 : two color, dark at min z, light at other, gradient
** style 3 : 3 color gradient according to z value
*/

void	set_style(t_matrix *a, t_matrix *b, t_data *new, t_mlx *mlx)
{
	if (mlx->color_style == 1)
	{
		new->a_color = a->color;
		if (a->color == 0)
			new->a_color = 0xffffff;
		new->b_color = b->color;
		if (b->color == 0)
			new->b_color = 0xffffff;
		new->color = new->a_color;
	}
	if (mlx->color_style == 2)
		style_2(a, b, new);
	if (mlx->color_style == 3)
		style_3(a, b, new, mlx);
}

/*
** generating color between 2 different colors for gradient with 
** linear interpolation between the color channels that are separated by
** bit shifting
*/

int	set_color(t_data ab)
{
	double	percentage;
	int		r;
	int		g;
	int		b;

	if (ab.color == ab.b_color)
		return (ab.color);
	if (ab.dx > ab.dy)
		percentage = percent(ab.startx, ab.bx, ab.ax);
	else
		percentage = percent(ab.starty, ab.by, ab.ay);
	r = ft_lerp_int(((ab.a_color >> 16) & 0xFF),
			((ab.b_color >> 16) & 0xFF), percentage);
	g = ft_lerp_int(((ab.a_color >> 8) & 0xFF),
			((ab.b_color >> 8) & 0xFF), percentage);
	b = ft_lerp_int(ab.a_color & 0xFF, ab.b_color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}
