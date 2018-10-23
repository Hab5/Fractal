/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:23:19 by mbellaic          #+#    #+#             */
/*   Updated: 2018/10/23 01:23:21 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			init_julia(t_mlx *mlx)
{
	mlx->iter_max = 200;
	mlx->frac.colorfactor = 253;
	mlx->frac.col = 0x0000FF;
	mlx->frac.x = 0;
	mlx->frac.y = 0;
	mlx->frac.x1 = -1.50;
	mlx->frac.x2 = 1.65;
	mlx->frac.y1 = -1.2;
	mlx->frac.y2 = 1.2;
	mlx->wid_x = 0;
	mlx->wid_y = 0;
	mlx->zoom = 250;
	mlx->i_jul = 1;
}

void			julia(t_mlx *mlx)
{
	double		tmp;
	double		c_r;
	double		c_i;

	c_r = 0.285;
	c_i = 0.01;
	mlx->frac.c_r = c_r * mlx->i_jul;
	mlx->frac.c_i = c_i * mlx->i_jul;
	mlx->frac.z_r = mlx->frac.x / mlx->zoom + mlx->frac.x1;
	mlx->frac.z_i = mlx->frac.y / mlx->zoom + mlx->frac.y1;
	mlx->frac.i = -1;
	while (mlx->frac.z_r * mlx->frac.z_r + mlx->frac.z_i * mlx->frac.z_i < 4 \
			&& ++mlx->frac.i < mlx->iter_max)
	{
		tmp = mlx->frac.z_r;
		mlx->frac.z_r = mlx->frac.z_r * mlx->frac.z_r \
						- mlx->frac.z_i * mlx->frac.z_i + mlx->frac.c_r;
		mlx->frac.z_i = 2 * mlx->frac.z_i * tmp + mlx->frac.c_i;
	}
	if (mlx->frac.i == mlx->iter_max)
		mlx->img.data[mlx->frac.y * WIN_WIDTH + mlx->frac.x] = 0x00FFFFFF;
	else
		mlx->img.data[mlx->frac.y * WIN_WIDTH + mlx->frac.x] =
			(int)(mlx->frac.col * mlx->frac.i \
				* mlx->frac.col / mlx->frac.colorfactor);
}

int				load_julia(t_mlx *mlx)
{
	init_mlx(mlx);
	init_julia(mlx);
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	legend(mlx);
	mlx_string_put(mlx->mlx, mlx->win, \
	460, 5, 0x00FFFFFF, "Modify Julia with < & >");
	if (mlx->space == 0)
		mlx_hook(mlx->win, 6, (1L << 6), &mouse_move, mlx);
	mlx_mouse_hook(mlx->win, &mouse_hook, mlx);
	mlx_key_hook(mlx->win, &key_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

void			julia_hook(int key, t_mlx *mlx)
{
	if (key == 43)
		mlx->i_jul *= 0.97;
	if (key == 47)
		mlx->i_jul *= 1.03;
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
