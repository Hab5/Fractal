#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 720

typedef struct		s_frac
{
	double			im_x;
	double			im_y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	unsigned int	i;
	unsigned int	x;
	unsigned int	y;
	int				col;
	int				colorfactor;
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

void				init_mandel(t_mlx  *mlx);
void				mandel(t_mlx *mlx);
int					load_mandel(t_mlx *mlx);

void				init_julia(t_mlx *mlx);
void				julia(t_mlx *mlx);
int					load_julia(t_mlx *mlx);

void				init_burning(t_mlx *mlx);
void				burning(t_mlx *mlx);
int					load_burning(t_mlx *mlx);

void				misc(int key, t_mlx *mlx);
void				reset(int key, t_mlx *mlx);
void				multi(int key, t_mlx *mlx);
void				zoom(t_mlx *mlx, double x, double y);
void				dezoom(t_mlx *mlx);
void				legend(t_mlx *mlx);
void				put_pixel_img(t_mlx *mlx);

int					key_hook(int key, t_mlx *mlx);
int					mouse_hook(int key, int x, int y, t_mlx *mlx);

#endif