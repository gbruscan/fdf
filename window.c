#include "fdf.h"

int 	ft_key_funct(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_window(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "fdf");
	mlx_key_hook(win, *ft_key_funct, 0);
	mlx_loop(mlx);
}
