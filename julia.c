#include "fractol.h"

void	init_julia(t_mlx *mlx)
{
	mlx->iter_max = 150;
	mlx->frac.col = 0x0000FF;
	mlx->frac.x = 0;
	mlx->frac.y = 0;
	mlx->frac.x1 = -1.35;
	mlx->frac.x2 = 1.35;
	mlx->frac.y1 = -1.2;
	mlx->frac.y2 = 1.2;
	mlx->wid_x = 0;
	mlx->wid_y = 0;
	mlx->zoom = 300;
	mlx->i_jul = 1;
}

void    julia(t_mlx *mlx)
{
	double		tmp;
	double		c_r;
	double		c_i;
	int			iter_max;

	c_r = 0.285;
	c_i = 0.01;
	mlx->frac.c_r = c_r * mlx->i_jul;
	mlx->frac.c_i = c_i * mlx->i_jul;
	mlx->frac.z_r = mlx->frac.x / mlx->zoom + mlx->frac.x1;
	mlx->frac.z_i = mlx->frac.y / mlx->zoom + mlx->frac.y1;
	mlx->frac.i = 0;
	iter_max = mlx->iter_max;
	while (mlx->frac.z_r * mlx->frac.z_r + mlx->frac.z_i * mlx->frac.z_i < 4 && ++mlx->frac.i < iter_max)
	{
		tmp = mlx->frac.z_r;
		mlx->frac.z_r = mlx->frac.z_r * mlx->frac.z_r - mlx->frac.z_i * mlx->frac.z_i + mlx->frac.c_r;
		mlx->frac.z_i = 2 * mlx->frac.z_i * tmp + mlx->frac.c_i;
	}
	if (mlx->frac.i == iter_max)
		mlx->img.data[mlx->frac.y * WIN_HEIGHT + mlx->frac.x] = 0x00FFFFFF;
	else
		mlx->img.data[mlx->frac.y * WIN_WIDTH + mlx->frac.x] =
			(int)(mlx->frac.col * mlx->frac.i * mlx->frac.col / iter_max);
}

int		load_julia(t_mlx *mlx)
{
	init_julia(mlx);
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_mouse_hook(mlx->win, &mouse_hook, mlx);
	mlx_key_hook(mlx->win, &key_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}