#include "../include/fractol.h"

void	put_pixel_img(t_mlx *mlx)
{
	mlx->frac.x = -1;
	while (++mlx->frac.x < WIN_WIDTH)
	{
		mlx->frac.y = -1;
		while (++mlx->frac.y < WIN_HEIGHT)
		{
				if (ft_strcmp(mlx->argv, "mandelbrot") == 0)
					mandel(mlx);
				else if (ft_strcmp(mlx->argv, "julia") == 0)
					julia(mlx);
				else if (ft_strcmp(mlx->argv, "burningship") == 0)
					burning(mlx);
				else
					exit (1);
		}
	}
}

void	zoom(t_mlx *mlx, double x, double y)
{
	mlx->wid_x = (mlx->frac.x2 - mlx->frac.x1) / 2;
	mlx->wid_y = (mlx->frac.y2 - mlx->frac.y1) / 2;
	mlx->frac.x1 = x - mlx->wid_x * 0.95;
	mlx->frac.x2 = x + mlx->wid_x * 0.95;
	mlx->frac.y1 = y - mlx->wid_y * 0.95;
	mlx->frac.y2 = y + mlx->wid_y * 0.95;
	mlx->zoom *= 1.05;
	mlx->iter_max++;
}

void	move(int key, t_mlx *mlx)
{
	if (key == 123)
		mlx->frac.x1 -= 20 / mlx->zoom;
	if (key == 126)
		mlx->frac.y1 -= 20 / mlx->zoom;
	if (key == 124)
		mlx->frac.x1 += 20 / mlx->zoom;
	if (key == 125)
		mlx->frac.y1 += 20 / mlx->zoom;
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}

void	misc(int key, t_mlx *mlx)
{
	if (key == 13)
		mlx->zoom *= 1.05;
	if (key == 12)
		mlx->iter_max++;
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
