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
#include <stdio.h>
float 	ft_get_up(int a, int b)
{
	float 	c;
	int 	d;

	d = SPACE / b;
	c = a / d;
	printf("%f\n", c);
	return (c);
}

void 	ft_draw_to_next(int i, int j, t_env map, int b)
{
	int 	a;
	int 	k;
	float   c;

	a = 0;
	k = 1;
	while (a < SPACE/b)
	{
		c = ft_get_up(map.map[i][j + 1], b);
		if (a < map.map[i][j])
		{
			c = c * k;
			mlx_pixel_put(map.mlx, map.win, BEGIN + j * SPACE/b + a, BEGIN + i * SPACE/b - c, 0xFFFFFF);
			k += 1;
		}
		else 
			mlx_pixel_put(map.mlx, map.win, BEGIN + j * SPACE/b + a, BEGIN + i * SPACE/b - map.map[i][j], 0xFFFFFF);
		a++;
	}
}

void 	ft_draw_to_lower(int i, int j, t_env map, int b)
{
	int 	a;
	int 	k;
	float 	c;

	a = 0;
	k = 1;
	while (a < SPACE/b)
	{	
		c = ft_get_up(map.map[i + 1][j], b);
		if (a < SPACE / b)
		{
			mlx_pixel_put(map.mlx, map.win, BEGIN + j * SPACE/b - c * k, BEGIN + i * SPACE/b + a, 0xFFFFFF);
			k += 1;
		}
		else
			mlx_pixel_put(map.mlx, map.win, BEGIN + j * SPACE/b, BEGIN + i * SPACE/b - map.map[i][j] + a, 0xFFFFFF);
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
			mlx_pixel_put(map.mlx, map.win, BEGIN + j * SPACE/b, BEGIN + i * SPACE/b - map.map[i][j], 0xFFFFFF);
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
