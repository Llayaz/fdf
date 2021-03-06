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

# define ARROW_UP		65362
# define ARROW_DOWN		65364
# define ARROW_LEFT		65361
# define ARROW_RIGHT	65363

# define KEY_ESC		65307
# define KEY_I			105
# define KEY_P			112
# define KEY_O			111
# define KEY_E			114
# define KEY_D			100
# define KEY_R			101
# define KEY_F			102
# define KEY_T			116
# define KEY_G			103

# define MAIN_PAD_1		49
# define MAIN_PAD_2		50
# define MAIN_PAD_3		51

# define MAIN_PAD_8		56
# define MAIN_PAD_9		57
# define MAIN_PAD_PLUS	43
# define MAIN_PAD_MINUS	45

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
	double	ax;
	double	ay;
	float	az;
	double	bx;
	double	by;
	float	bz;
	float	dx;
	float	dy;
	double	startx;
	double	starty;
	float	step_x;
	float	step_y;
	float	max;
	int		a_color;
	int		b_color;
	int		color;
}	t_data;

typedef struct s_matrix
{
	size_t	x;
	size_t	y;
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
	double		angle;
	double		alpha;
	double		beta;
	double		gamma;
	float		scale;
	float		scale_z;
	float		is_iso;
	float		offset_x;
	float		offset_y;
	size_t		color_style;
}	t_mlx;

void	my_pixel_put(t_img *img, int x, int y, int color);
void	new_img(t_mlx *mlx);
int		deal_key(int key_nb, t_mlx *mlx);
int		close_window(t_mlx *mlx);
void	clearup(t_mlx *mlx);
void	kill_err(char *err);
void	kill_mlx(char *err, t_mlx *mlx);
void	kill_all(char *err, char **arr, t_mlx *mlx);
void	get_length(char *file, t_mlx *mlx);
void	set_default(t_mlx *mlx);
void	make_map(char *file, t_mlx *mlx);
void	draw_img(t_mlx *mlx);
void	draw_line(t_matrix a, t_matrix b, t_mlx *mlx);
void	lineclip(t_matrix a, t_matrix b, t_mlx *mlx);
t_data	adj_data(t_matrix a, t_matrix b, t_mlx *mlx);
int		is_valid(char *str, t_mlx *mlx);
int		is_color(char *str);
float	set_max(float a, float b);
int		set_color(t_data ab);
void	set_style(t_matrix *a, t_matrix *b, t_data *new, t_mlx *mlx);
void	write_instruct(t_mlx *mlx);
void	rotate_x(t_data *new, t_mlx *mlx);
void	rotate_y(t_data *new, t_mlx *mlx);
void	rotate_z(t_data *new, t_mlx *mlx);
void	move_key(int key_nb, t_mlx *mlx);
void	projection_rotation(int key_nb, t_mlx *mlx);
int		key_pressed(int key_nb, t_mlx *mlx);

#endif
