/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:34:14 by ncsomori          #+#    #+#             */
/*   Updated: 2022/03/30 18:34:22 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	float	ax;
	float	ay;
	float	az;
	float	bx;
	float	by;
	float	bz;
	float	dx;
	float	dy;
	float	startx;
	float	starty;
	float	step_x;
	float	step_y;
	float	max;
	int		a_color;
	int		b_color;
	int		color;
}	t_data;

typedef struct s_matrix
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_matrix;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_matrix	**map;
	size_t		win_x;
	size_t		win_y;
	size_t		width;
	size_t		height;
	float		max_z;
	float		min_z;
	float		angle;
	float		scale;
	float		scale_z;
	float		is_iso;
	float		offset_x;
	float		offset_y;
	size_t		color_style;
}	t_mlx;

void	kill_err(char *err);
void	kill_array(char **arr);
void	get_length(char *file, t_mlx *mlx);
void	set_default(t_mlx *mlx);
void	make_map(char *file, t_mlx *mlx);
int		deal_key(int key_nb, t_mlx *mlx);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw_img(t_mlx *mlx);
void	draw_line(t_matrix a, t_matrix b, t_mlx *mlx);
t_data	adj_data(t_matrix a, t_matrix b, t_mlx *mlx);
int		is_valid(char *str);
int		is_color(char *str);
float	set_max(float a, float b);
void	clearup(t_mlx *mlx);
void	lineclip(t_matrix a, t_matrix b, t_mlx *mlx);
int		set_color(t_data ab);
void	set_style(t_matrix *a, t_matrix *b, t_data *new, t_mlx *mlx);
void	write_instruct(t_mlx *mlx);

#endif
