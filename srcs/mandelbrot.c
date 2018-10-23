/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:23:30 by mbellaic          #+#    #+#             */
/*   Updated: 2018/10/23 01:23:33 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_mandel(t_mlx *mlx)
{
	mlx->iter_max = 100;
	mlx->frac.colorfactor = 84;
	mlx->frac.col = 0x0000FF;
	mlx->frac.x = 0;
	mlx->frac.y = 0;
	mlx->frac.x1 = -2.1;
	mlx->frac.x2 = 0.6;
	mlx->frac.y1 = -1.2;
	mlx->frac.y2 = 1.2;
	mlx->wid_x = 0;
	mlx->wid_y = 0;
	mlx->zoom = 250;
}

void	mandel(t_mlx *mlx)
{
	double		tmp;

	mlx->frac.c_r = mlx->frac.x / (double)(mlx->zoom) + mlx->frac.x1;
	mlx->frac.c_i = mlx->frac.y / (double)(mlx->zoom) + mlx->frac.y1;
	mlx->frac.z_r = 0;
	mlx->frac.z_i = 0;
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
		mlx->img.data[mlx->frac.y * WIN_WIDTH + mlx->frac.x] = 0;
	else
		mlx->img.data[mlx->frac.y * WIN_WIDTH + mlx->frac.x] =
			(int)(mlx->frac.col * mlx->frac.i * mlx->frac.col \
				/ mlx->frac.colorfactor);
}

int		load_mandel(t_mlx *mlx)
{
	init_mlx(mlx);
	init_mandel(mlx);
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	legend(mlx);
	mlx_mouse_hook(mlx->win, &mouse_hook, mlx);
	mlx_key_hook(mlx->win, &key_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
