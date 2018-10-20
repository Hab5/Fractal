#include "../include/fractol.h"

int		expose_hook(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.data, 0, 0);
	return (0);
}

int		key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		exit (1);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, mlx);
	if (key == 12 || key == 13)
		misc(key, mlx);
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