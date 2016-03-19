#include "fdf.h"
#include <stdio.h>

float 	ft_get_b(t_env map)
{
	float b;

	if (map.x < map.y)
		b = map.y;
	else
		b = map.x;
	map.a = 0;
	map.c = 0;
	return (b);
}

float 	ft_get_Y(int j, int i, float z)
{
	float 	f;

	f = z + 0.4 * j + 0.3 * i;
	return (f);
}

void 	ft_draw_line(t_env map, int j, int i)
{
	float 	a;
	int 	y1;
	int 	y2;

	a = j;
	while (a <= SPACE)
	{
		y1 = ft_get_Y(j , i, map.map[i][j]);
		y2 = ft_get_Y(j + 1, i , map.map[i][j + 1]);
		mlx_pixel_put(map.mlx, map.win, BEGIN_X + a, BEGIN_Y + y1 + ((y2 - y1) * (a - j) / (map.x - j)), 0xFFFFFF);
		a += 0.01;
	}
}

void	ft_draw_map(t_env map)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;		
	mlx_pixel_put(map.mlx, map.win, BEGIN_X, BEGIN_Y, 0xFFFFFF);
	ft_draw_line(map, j, i);
	j++;
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
//	map.b = ft_get_b(map.x, map.y);
	map.b = ft_get_b(map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1200, 1200, "fdf");
	ft_draw_map(map);
	mlx_key_hook(map.win, *ft_key_funct, 0);
	mlx_loop(map.mlx);
}
