#include "fractol.h"

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
	mlx->zoom *= 1.1;
	//mlx->iter_max++;
}

void	other(int key, t_mlx *mlx)
{
	if (key == 13)
		mlx->zoom *= 1.05;
	if (key == 12)
		mlx->iter_max++;
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
void	move(int key, t_mlx *mlx)
{
	if (key == 124)
		mlx->frac.x1 -= 10 / mlx->zoom;
	if (key == 125)
		mlx->frac.y1 -= 10 / mlx->zoom;
	if (key == 123)
		mlx->frac.x1 += 10 / mlx->zoom;
	if (key == 126)
		mlx->frac.y1 += 10 / mlx->zoom;
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}

int		key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		exit (1);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, mlx);
	if (key == 12 || key == 13)
		other(key, mlx);
	return (0);
}

int		mouse_hook(int boutton, int x, int y, t_mlx *mlx)
{
	double		mouse_x;
	double		mouse_y;

	mouse_x = x * ((mlx->frac.x2 - mlx->frac.x1) / WIN_WIDTH) + mlx->frac.x1;
	mouse_y = y * ((mlx->frac.y2 - mlx->frac.y1) / WIN_HEIGHT) + mlx->frac.y1;
	if (boutton == 6)
		(mlx->zoom < 1964714736118) ? zoom(mlx, mouse_x, mouse_y) : 0;
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}