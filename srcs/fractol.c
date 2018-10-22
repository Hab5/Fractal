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

void     init_mlx(t_mlx  *mlx)
{
    mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "FRACT'OL");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
    mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
}

int	        main(int argc, char **argv)
{
	t_mlx	mlx;

    mlx.argv = argv[1];
    if (argc == 2)
    {
	    if (ft_strcmp(argv[1], "mandelbrot") == 0)
            load_mandel(&mlx);
        else if (ft_strcmp(argv[1], "julia") == 0)
            load_julia(&mlx);
        else if (ft_strcmp(argv[1], "burningship") == 0)
            load_burning(&mlx);
        else
            ft_putendl("Usage: ./fractol [mandelbrot][julia][burningship]");
    }
    else
    {
        ft_putendl("Usage: ./fractol [mandelbrot][julia][burningship]");
	    return (0);
    }
}