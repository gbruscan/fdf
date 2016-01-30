#include "fdf.h"

int 	ft_isint(int i)
{
	if (i >= -32768 && i <= 32767)
		return (1);
	return (0);
}

void 	ft_map_size(int **map)//(int **map, int *x, int *y)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	ft_putnbr(map[11][0]);
/*	while (map[i])
	{
		i++;
		ft_putnbr(i);
		ft_putchar('\n');
	}*/
}

int 	ft_key_funct(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_window(int **map)
{
	void	*mlx;
	void	*win;
//	int 	x;
//	int 	y;

	ft_map_size(map);
//	ft_map_size(map, &x, &y);
//	ft_putnbr(x);
//	ft_putchar('\n');
//	ft_putnbr(y);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "fdf");
	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	mlx_key_hook(win, *ft_key_funct, 0);
	mlx_loop(mlx);
}
