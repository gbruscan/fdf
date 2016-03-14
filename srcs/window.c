#include "fdf.h"
#include <stdio.h>

float 	ft_get_b(int a, int c)
{
	float b;

	if (a < c)
		b = c;
	else
		b = a;
	return (b);
}

void 	ft_twotwo(t_env map, float b, int i, float c)
{
	float	a;

	a = 0;
	while (a < SPACE/b && i + 1 < map.y)
	{
		mlx_pixel_put(map.mlx, map.win, BEGIN_X - i * SPACE/b + c * SPACE/b - a, BEGIN_Y + i * SPACE/b + c * SPACE/b + a, 0xFFFFFF);
		a += 0.01;
	}
}

void	ft_oneone(t_env map, float b, int i)
{
	float 	c;
	float 	a;
	int 	j;

	c = 0;
	a = 0;
	j = 0;
	while (c < map.x)
	{
		while (a < SPACE/b && c + 1 < map.x)
		{
			mlx_pixel_put(map.mlx, map.win, BEGIN_X - i * SPACE/b + c * SPACE/b + a, BEGIN_Y + i * SPACE/b + c * SPACE/b + a, 0xFFFFFF);
			a += 0.01;
		}
		mlx_pixel_put(map.mlx, map.win, BEGIN_X - i * SPACE/b + c * SPACE/b, BEGIN_Y + i * SPACE/b + c * SPACE/b - 3 * map.map[i][j], 0xFFFFFF);
		ft_twotwo(map, b, i, c);
		c++;
		j++;
		a = 0;
	}
}

void	ft_draw_map(t_env map, float b)
{
	int 	i;
	int 	j;
	float 	a;

	i = 0;
	j = 0;
	a = 0;
	while (i < map.y)
	{
		mlx_pixel_put(map.mlx, map.win, BEGIN_X - i * SPACE/b, BEGIN_Y + i * SPACE/b - 3 * map.map[i][j], 0xFFFFFF);
		ft_oneone(map, b, i);
		i++;
		a = 0;
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
