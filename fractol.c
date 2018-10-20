#include "fractol.h"

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
    
    init_mlx(&mlx);
    mlx.argv = argv[1];
    if (argc == 2)
    {
	    if (ft_strcmp(argv[1], "mandelbrot") == 0)
            load_mandel(&mlx);
        if (ft_strcmp(argv[1], "julia") == 0)
            load_julia(&mlx);
    }
    else
        exit(1);
    mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}