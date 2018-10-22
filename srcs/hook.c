#include "../include/fractol.h"

int		key_hook(int key, t_mlx *mlx)
{
	char *iteration; 
	
	if (key == 53)
		exit (1);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		misc(key, mlx);
	if (key == 12 || key == 13 || key == 15)
		misc(key, mlx);
	if (key == 18 || key == 19 || key == 20)
		multi(key, mlx);
	iteration = ft_strjoin("Iteration : ", ft_itoa(mlx->iter_max));
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0x00FFFFFF, iteration);
	
	return (0);
}

int		mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	double		mouse_x;
	double		mouse_y;
	char *iteration;
	
	mouse_x = x * ((mlx->frac.x2 - mlx->frac.x1) / WIN_WIDTH) + mlx->frac.x1;
	mouse_y = y * ((mlx->frac.y2 - mlx->frac.y1) / WIN_HEIGHT) + mlx->frac.y1;
	if (key == 6)
		(mlx->zoom < 1964714736118) ? zoom(mlx, mouse_x, mouse_y) : 0;
	else if (key == 7)
		dezoom(mlx);
	put_pixel_img(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	iteration = ft_strjoin("Iteration : ", ft_itoa(mlx->iter_max));
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0x00FFFFFF, iteration);
	return (0);
}