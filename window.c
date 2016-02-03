#include "fdf.h"

int 	ft_get_b(int a, int c)
{
	int b;

	if (a < c)
		b = c;
	else
		b = a;
	return (b);
}

void 	ft_draw_to_next(int i, int j, t_env map, int b)
{
	int 	a;

	a = 0;
	while (a < SPACE/b)
	{
		mlx_pixel_put(map.mlx, map.win, BEGIN + j * SPACE/b + a, BEGIN + i * SPACE/b, 0xFFFFFF);
		a++;
	}
}

void 	ft_draw_to_lower(int i, int j, t_env map, int b)
{
	int 	a;

	a = 0;
	while (a < SPACE/b)
	{
		mlx_pixel_put(map.mlx, map.win, BEGIN + j * SPACE/b, BEGIN + i * SPACE/b + a, 0xFFFFFF);
		a++;
	}
}

void	ft_draw_map(t_env map, int b)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (i < map.y)
	{
		while (j < map.x)
		{
			mlx_pixel_put(map.mlx, map.win, BEGIN + j * SPACE/b, BEGIN + i * SPACE/b, 0xFFFFFF);
			if (j + 1 < map.x)
				ft_draw_to_next(i ,j, map, b);
			if (i + 1 < map.y)
				ft_draw_to_lower(i ,j, map, b);
			j++;
		}
		j = 0;
		i++;
	}
}

int 	ft_key_funct(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_window(t_env map)
{
	int 	b;

	b = ft_get_b(map.x, map.y);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1200, 1200, "fdf");
	ft_draw_map(map, b);
	mlx_key_hook(map.win, *ft_key_funct, 0);
	mlx_loop(map.mlx);
}
