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

int	parse_color(char *str)
{
	char	**parts;
	int		i;

	i = 0;
	parts = ft_strsplit(str, ',');
	if (!parts)
		kill_err("Failed to parse");
	if (parts[1][0] == '\0')
		return (98298);
	if (is_color(parts[1]) == 1)
		return (atoi(parts[1]));
	ft_free_array(parts);
	return (1);
}

void	parse_map(char *line, t_mlx *mlx, size_t y)
{
	char	**arr;
	size_t	i;

	i = 0;
	arr = ft_strsplit(line, ' ');
	if (!arr)
		kill_err("Failed to parse");
	while (i < mlx->width)
	{
//		printf("arr in parse %p\n",(void *)&arr[i]);
		if (is_valid(arr[i]) != 1)
			kill_err("Invalid map");
		mlx->map[y][i].z = ft_atoi(arr[i]);
		mlx->map[y][i].x = i;
		mlx->map[y][i].y = y;
//		printf("%p\n", (void *)&mlx->map[y][i].z);
		i++;
	}
	ft_free_array(arr);
}

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

//remove before submission from h too!
void	print_map(t_matrix **map, t_mlx *mlx)
{
	size_t	i = 0, j = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			printf("X is %d, y is %d\n", map[i][j].x, map[i][j].y);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			printf(" %d ", map[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}
