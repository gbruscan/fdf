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

float 	ft_get_X(int j, int i)
{
	float 	f;

	f = 0.8 * j - 0.6 * i;
	return (f);
}

float 	ft_get_Y(int j, int i, int z)
{
	float 	f;

	f = z + 0.4 * j + 0.3 * i;
	return (f);
}

void 	ft_pixel_next(t_env map)
{


}

void	ft_draw_map(t_env map)
{
	int 	i;
	int 	j;
	float 	X;
	float 	Y;

	i = 0;
	j = 0;
	while (j < map.x)
	{
		X = ft_get_X(j, i);
		Y = ft_get_Y(j, i, map.map[i][j]);		
		mlx_pixel_put(map.mlx, map.win, BEGIN_X + X + j * SPACE/map.b, BEGIN_Y + Y + j * SPACE/map.b, 0xFFFFFF);
		ft_pixel_next(map, )
		j++;
	}
	printf("j = %d\n", j);
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
