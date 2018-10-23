/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:25:43 by mbellaic          #+#    #+#             */
/*   Updated: 2018/10/23 01:25:44 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread/pthread.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH 700
# define WIN_HEIGHT 600

typedef struct		s_frac
{
	long double		im_x;
	long double		im_y;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	unsigned int	i;
	unsigned int	x;
	unsigned int	y;
	unsigned int	col;
	unsigned int	colorfactor;
}					t_frac;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*key;
	void			*mouse;
	double			zoom;
	double			pad;
	double			wid_x;
	double			wid_y;
	double			i_jul;
	unsigned int	iter_max;
	char			*argv;
	t_frac			frac;
	t_img			img;
}					t_mlx;

void				init_mlx(t_mlx *mlx);

void				init_mandel(t_mlx *mlx);
void				mandel(t_mlx *mlx);
int					load_mandel(t_mlx *mlx);

void				init_julia(t_mlx *mlx);
void				julia(t_mlx *mlx);
int					load_julia(t_mlx *mlx);

void				init_burning(t_mlx *mlx);
void				burning(t_mlx *mlx);
int					load_burning(t_mlx *mlx);

void				init_tricorn(t_mlx *mlx);
void				tricorn(t_mlx *mlx);
int					load_tricorn(t_mlx *mlx);

void				misc(int key, t_mlx *mlx);
void				reset(t_mlx *mlx);
void				multi(int key, t_mlx *mlx);
void				zoom(t_mlx *mlx, double x, double y);
void				dezoom(t_mlx *mlx, double x, double y);
void				legend(t_mlx *mlx);
void				julia_hook(int key, t_mlx *mlx);
void				put_pixel_img(t_mlx *mlx);

int					key_hook(int key, t_mlx *mlx);
int					mouse_move(int x, int y, t_mlx *mlx);
int					mouse_hook(int key, int x, int y, t_mlx *mlx);

#endif
