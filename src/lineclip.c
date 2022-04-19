/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineclip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:23:12 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/09 17:23:14 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** in case ax or ay is not in the window, lineclip tries to draw pixels
** starting from bx and by if any of those are still in the window
*/

void	lineclip(t_matrix a, t_matrix b, t_mlx *mlx)
{
	t_data	line_ab;
	float	step_x;
	float	step_y;
	float	max;

	line_ab = adj_data(b, a, mlx);
	step_x = line_ab.bx - line_ab.ax;
	step_y = line_ab.by - line_ab.ay;
	max = set_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)(line_ab.ax - line_ab.bx) || (int)(line_ab.ay - line_ab.by))
	{
//		if (line_ab.ax > (mlx->win_x - 1) || line_ab.ay > mlx->win_y
//			|| line_ab.ay < 0 || line_ab.ax < 0)
//			break ;
		if (line_ab.a_color != line_ab.b_color)
			line_ab.color = set_color(line_ab);
		if (line_ab.ax < (mlx->win_x - 1) && line_ab.ay < mlx->win_y
			&& line_ab.ay > 0 && line_ab.ax > 0)
			my_pixel_put(&mlx->img, line_ab.ax, line_ab.ay, line_ab.color);
		line_ab.ax += step_x;
		line_ab.ay += step_y;
	}
}
