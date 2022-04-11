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

void	clearup(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->map)
	{	
		if (mlx->map[i])
		{
			free(mlx->map[i]);
			i++;
		}
	free(mlx->map);
	}
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
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (str[i] == '\0')
			return (0);
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
	if (str[i] != 0)
		return (0);
	i++;
	if (str[i] != 'x')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (ft_isxdigit(str[i] != 1))
			return (0);
		j++;
		i++;
	}
	if (j > 6)
		return (0);
	return (1);
}

int	is_valid(char *str)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(str, ',');
	if (!arr)
		kill_err("Parsing error");
	if (arr[i][0] != '\0')
		i++;
	if (i > 2)
		return (0);
	if (i == 1)
		if (is_num(arr[0]) == 1)
			return (1);
	if (i == 2)
		if (is_num(arr[0]) == 1 && is_color(arr[1]) == 1)
			return (1);
	ft_free_array(arr);
	return (0);
}
