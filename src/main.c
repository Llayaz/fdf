/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:02:04 by ncsomori          #+#    #+#             */
/*   Updated: 2022/03/30 15:02:07 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		kill_err("Usage: ./fdf input_file");
	get_length(argv[1], &mlx);
	set_default(&mlx);
	make_map(argv[1], &mlx);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		kill_mlx("Allocation error", &mlx);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1440, 900, "FDF");
	if (mlx.win_ptr == NULL)
		kill_mlx("Allocation error", &mlx);
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, 1440, 900);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bpp,
			&mlx.img.line_len, &mlx.img.endian);
	mlx_set_font(mlx.mlx_ptr, mlx.win_ptr, "-*-corbel-*-*-*-*-*-*-*-*-*-*-*-*");
	draw_img(&mlx);
	return (0);
}
