/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:27:15 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/08 19:27:19 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
** check for line validity
** line has to have at least 2 digits to be a valid map
** it has to be at least 4 char long to be valid
*/

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		kill_err("Failed to open file");
	return (fd);
}

void	check_line(char *line)
{
	int	i;
	int	dig;

	i = 0;
	dig = 0;
	while (line[i] != '\0')
	{
		if ((i == 0 && ft_isdigit(line[i]) == 1)
			|| (i != 0 && line[i - 1] == ' ' && ft_isdigit(line[i]) == 1))
			dig++;
		i++;
	}
	if (i < 4 || dig < 2)
	{
		ft_strdel(&line);
		kill_err("Invalid map");
	}
}

/*
** checking that line length is same for all lines
** getting height for map
*/

void	get_length(char *file, t_mlx *mlx)
{
	int		fd;
	int		ret;
	char	*line;
//	int		i;

//	i = 0;
	mlx->height = 0;
	fd = open_file(file);
	ret = get_next_line(fd, &line);
	if (ret == 0)
		kill_err("Empty map");
	check_line(line);
	if (ret > 0)
		mlx->width = (int)ft_word_count(line, ' ');
	while (ret != 0)
	{
		if (ret < 0)
			kill_err("Failed to read");
		ft_strdel(&line);
		ret = get_next_line(fd, &line);
		if (ft_word_count(line, ' ') != mlx->width && ret != 0)
			kill_err("Invalid map");
//		i++;
		mlx->height++;
	}
//	mlx->height = i;
	if (close(fd) < 0)
		kill_err("Failed to close file");
}

/*
** setting default environmental values
*/

void	set_default(t_mlx *mlx)
{
	mlx->win_x = 1440;
	mlx->win_y = 900;
	mlx->angle = 0.53599;
	mlx->scale = mlx->win_x / (mlx->height * 2);
	if (mlx->width >= mlx->height)
		mlx->scale = mlx->win_x / (mlx->width * 2);
	if (mlx->scale < 5)
		mlx->scale = 5;
	mlx->scale_z = 5;
	mlx->max_z = 0;
	mlx->min_z = 0;
	mlx->is_iso = 0;
	mlx->offset_x = (mlx->width * mlx->scale) / 2  - mlx->win_x / 2;
	if (mlx->width < mlx->win_x)
		mlx->offset_x = mlx->win_x / 2 - (mlx->width * mlx->scale) / 2;
//	if (mlx->offset_x <= 0 || mlx->offset_x > mlx->win_x)
//		mlx->offset_x = 0;
	mlx->offset_y = (mlx->height * mlx->scale) / 2 - mlx->win_y / 2;
	if (mlx->width < mlx->win_x)
		mlx->offset_y = mlx->win_y / 2 - (mlx->height * mlx->scale) / 2;
//	if (mlx->offset_y <= 0 || mlx->offset_y > mlx->win_y)
//		mlx->offset_y = 0;
	mlx->color_style = 2;
}
