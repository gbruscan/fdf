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

void	ft_utod(int i, int j, t_env map, float b)
{
/*	float 	a;

	a = 0;
	(void)j;
	while (a < SPACE/b)
	{
		mlx_pixel_put(map.mlx, map.win, BEGIN_X - i * SPACE/b - a, BEGIN_Y + i * SPACE/b + a, 0xFFFFFF);
		a++;
	}*/
	(void)j;
	mlx_pixel_put(map.mlx, map.win, BEGIN_X - i * SPACE/b, BEGIN_Y + i * SPACE/b, 0xFFFFFF);
}

void	ft_ltor(int i, int j, t_env map, float b)
{
/*	float 	a;

	a = 0;
	(void)j;
	while (a < SPACE/b)
	{
		mlx_pixel_put(map.mlx, map.win, BEGIN_X + i * SPACE/b + a, BEGIN_Y + i * SPACE/b + a, 0xFFFFFF);
		a++;
	}
	*/
	(void)j;
	mlx_pixel_put(map.mlx, map.win, BEGIN_X + i * SPACE/b, BEGIN_Y + i * SPACE/b, 0xFFFFFF);
}

void	ft_draw_map(t_env map, float b)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;

	while (i < map.x)
	{
		if (i < map.y)
			ft_utod(i, j, map, b);			
		while (j < map.x)
		{
			ft_ltor(i, j, map, b);
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
