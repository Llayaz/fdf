/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:30:54 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/08 19:30:56 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** checks if there is color, if it is a valid str for hexadecimal, parses
** color for map
*/

int	parse_color(char *str)
{
	char	**parts;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	parts = ft_strsplit(str, ',');
	if (!parts)
		kill_err("Failed to parse in parse_color");
	while (parts[i] != NULL)
		i++;
	if (i > 2)
		kill_array(parts);
	if (parts[1] == NULL)
	{
		ft_free_array(parts);
		return (0);
	}
	if (is_color(parts[1]) != 1)
		kill_array(parts);
	ret = ft_atoi_hex(parts[1]);
	ft_free_array(parts);
	return (ret);
}

/* parsing line by line the x,y,z values */

void	parse_map(char *line, t_mlx *mlx, size_t y)
{
	char	**arr;
	size_t	i;

	i = 0;
	arr = ft_strsplit(line, ' ');
	if (!arr)
		kill_err("Failed to parse in parse_map");
	while (i < mlx->width)
	{
		if (is_valid(arr[i]) != 1)
			kill_err("Invalid map");
		mlx->map[y][i].z = ft_atoi(arr[i]);
		mlx->map[y][i].x = i;
		mlx->map[y][i].y = y;
		if (mlx->map[y][i].z > mlx->max_z)
			mlx->max_z = mlx->map[y][i].z;
		if (mlx->map[y][i].z < mlx->min_z)
			mlx->min_z = mlx->map[y][i].z;
		mlx->map[y][i].color = parse_color(arr[i]);
		i++;
	}
	ft_free_array(arr);
}

/*
** allocating struct array
*/

void	allocate_map(t_mlx *mlx)
{
	size_t	y;

	y = 0;
	mlx->map = ft_memalloc(sizeof(t_matrix *) * mlx->height);
	if (!mlx->map)
		kill_err("Failed to allocate");
	while (y < mlx->height)
	{
		mlx->map[y] = ft_memalloc(sizeof(t_matrix) * mlx->width);
		if (!mlx->map[y])
			kill_err("Failed to allocate");
		y++;
	}
}

void	make_map(char *file, t_mlx *mlx)
{
	int		fd;
	int		ret;
	char	*line;
	size_t	y;

	y = 0;
	allocate_map(mlx);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		kill_err("Failed to open file");
	ret = 1;
	while (y < mlx->height)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			kill_err("Failed to read");
		parse_map(line, mlx, y);
		ft_strdel(&line);
		y++;
	}
}
