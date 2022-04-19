/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:38:18 by ncsomori          #+#    #+#             */
/*   Updated: 2022/03/21 14:38:22 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_matrix *a, t_matrix *b, t_data *new, t_mlx *mlx)
{
	new->ax = (a->x - a->y) * mlx->scale * cos(mlx->angle) + mlx->offset_x;
	new->ay = (a->x + a->y) * mlx->scale * sin(mlx->angle)
		+ mlx->offset_y - (a->z * mlx->scale_z);
	new->bx = (b->x - b->y) * mlx->scale * cos(mlx->angle) + mlx->offset_x;
	new->by = (b->x + b->y) * mlx->scale * sin(mlx->angle)
		+ mlx->offset_y - (b->z * mlx->scale_z);
}

/*
** transforming data of a and b to struct for line for different projections
** and color schemes
*/

t_data	adj_data(t_matrix a, t_matrix b, t_mlx *mlx)
{
	t_data	new;

//	new = ft_malloc(sizeof(t_data));
//	if (!new)
//		kill_err("Failed to allocate");
	set_style(&a, &b, &new, mlx);
	if (mlx->is_iso == 1)
		isometric(&a, &b, &new, mlx);
	if (mlx->is_iso == 0)
	{
		new.ax = a.x * mlx->scale + mlx->offset_x;
		new.ay = a.y * mlx->scale + mlx->offset_y;
		new.az = a.z * mlx->scale_z;
		new.bx = b.x * mlx->scale + mlx->offset_x;
		new.by = b.y * mlx->scale + mlx->offset_y;
		new.bz = b.z * mlx->scale_z;
	}
	new.dx = ft_abs_f(new.bx - new.ax);
	new.dy = ft_abs_f(new.by - new.ay);
//	set_style(&a, &b, &new, mlx);
/*	new.a_color = a.color;
	if (a.color == 0)
		new.a_color = 0xffffff;
	new.b_color = b.color;
	if (b.color == 0)
		new.b_color = 0xffffff;
	new.color = a.color;*/
	new.startx = new.ax;
	new.starty = new.ay;
/*	if (a.color == 0 && b.color == 0)
	{
		new.color = 0x00ffffff;
		if (a.z != 0 || b.z != 0)
			new.color = 0xff00ff;
	}*/
	return (new);
}

void	draw_line(t_matrix a, t_matrix b, t_mlx *mlx)
{
	t_data	ab;
	float	step_x;
	float	step_y;
	float	max;

	ab = adj_data(a, b, mlx);
	step_x = ab.bx - ab.ax;
	step_y = ab.by - ab.ay;
	max = set_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)(ab.ax - ab.bx) || (int)(ab.ay - ab.by))
	{
		if (ab.ax > (mlx->win_x - 1) || ab.ay > mlx->win_y || ab.ay < 0 || ab.ax < 0)
		{
			if ((ab.bx > 0 && ab.bx < (mlx->win_x - 1))
				|| (ab.by > 0 && ab.by < (mlx->win_y)))
				lineclip(a, b, mlx);
			break ;
		}
		if (ab.a_color != ab.b_color)
			ab.color = set_color(ab);
		my_pixel_put(&mlx->img, ab.ax, ab.ay, ab.color);
		ab.ax += step_x;
		ab.ay += step_y;
	}
	if (ab.ax < (mlx->win_x - 1) && ab.ay < mlx->win_y && ab.ay > 0 && ab.ax > 0)
			my_pixel_put(&mlx->img, ab.ax, ab.ay, ab.color);
}

void	new_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
}

void	draw_img(t_mlx *mlx)
{
	size_t	x;
	size_t	y;

	y = 0;
	if (mlx->img.img != NULL)
		new_img(mlx);
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			if (y < (mlx->height - 1))
				draw_line(mlx->map[y][x], mlx->map[(y + 1)][x], mlx);
			if (x < (mlx->width - 1))
				draw_line(mlx->map[y][x], mlx->map[y][(x + 1)], mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	write_instruct(mlx);
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
