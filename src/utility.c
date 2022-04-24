/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:29:48 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/08 19:29:49 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, (int)mlx->win_x,
		(int)mlx->win_y);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
}

float	set_max(float a, float b)
{
	if (ft_abs_f(a) > ft_abs_f(b))
		return (ft_abs_f(a));
	return (ft_abs_f(b));
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i] != 1))
			return (0);
		i++;
	}
	return (1);
}

int	is_color(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] != '0')
		return (0);
	i++;
	if (str[i] != 'x')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (ft_isxdigit(str[i]) != 1)
			return (0);
		j++;
		i++;
	}
	if (j > 6)
		return (0);
	return (1);
}

/*
** checks if array 'z,color' is valid, z can only have numbers, color can only
** contain hexadecimal values for format 0xXXXXXXXX, color is not necessary
*/

int	is_valid(char *str, t_mlx *mlx)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(str, ',');
	if (!arr)
		kill_mlx("Parsing error", mlx);
	if (arr[i] != NULL)
		i++;
	if (i > 2)
		return (0);
	if (i == 1 && is_num(arr[0]))
	{
		ft_free_array(arr);
		return (1);
	}
	if (i == 2 && is_num(arr[0]) == 1 && is_color(arr[1]) == 1)
	{
		ft_free_array(arr);
		return (1);
	}
	ft_free_array(arr);
	return (0);
}
