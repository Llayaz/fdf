/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:48:46 by ncsomori          #+#    #+#             */
/*   Updated: 2022/04/20 15:48:49 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_mlx *mlx)
{
	clearup(mlx);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
	exit (0);
	return (0);
}

void	clearup(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	if (mlx->map)
	{
		while (i < mlx->height)
		{
			if (mlx->map[i])
				free(mlx->map[i]);
			i++;
		}
		free(mlx->map);
	}
}

void	kill_err(char *err)
{
	if (errno == EPERM || errno == EAGAIN)
		ft_putendl_fd(err, 2);
	else
		perror("Error");
//	system("leaks fdf");
	exit (1);
}

void	kill_mlx(char *err, t_mlx *mlx)
{
	if (errno == EPERM || errno == EAGAIN)
		ft_putendl_fd(err, 2);
	else
		perror("Error");
	if (mlx->map != NULL)
		clearup(mlx);
//	system("leaks fdf");
	exit (1);
}

void	kill_all(char *err, char **arr, t_mlx *mlx)
{
	if (errno == EPERM || errno == EAGAIN)
		ft_putendl_fd(err, 2);
	else
		perror("Error");
	clearup(mlx);
	ft_free_array(arr);
//	system("leaks fdf");
	exit(1);
}
