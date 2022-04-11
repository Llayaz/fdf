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
		kill_err("Invalid map");
}

void	get_length(char *file, t_mlx *mlx)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		perror("Error");
//		kill_err("Failed to open file");
	ret = get_next_line(fd, &line);
	if (ret == 0)
		perror("Error");
//		kill_err("Empty map");
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
		i++;
	}
	mlx->height = i;
	if (close(fd) < 0)
		kill_err("Failed to close file");
}

void	set_default(t_mlx *mlx)
{
	mlx->win_x = 1440;
	mlx->win_y = 900;
	mlx->angle = 0.53599;
	mlx->scale = 20;
	mlx->scale_z = 5;
	mlx->is_iso = 0;
	mlx->offset_x = mlx->win_x / 2 - (mlx->width * mlx->scale) / 2;
	if (mlx->offset_x <= 0 || mlx->offset_x > mlx->win_x)
		mlx->offset_x = 0;
	mlx->offset_y = mlx->win_y / 2 - (mlx->height * mlx->scale) / 2;
	if (mlx->offset_y <= 0 || mlx->offset_y > mlx->win_y)
		mlx->offset_y = 0;
}
