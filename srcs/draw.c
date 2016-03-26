#include "fdf.h"

void 	ft_draw_to_R(t_env map, int j, int i)
{
	float 	a;
	float 	x1;
	float 	x2;
	float 	y1;
	float 	y2;

	x1 = map.tab[i][j].X;
	x2 = map.tab[i][j + 1].X;
	y1 = map.tab[i][j].Y;
	y2 = map.tab[i][j + 1].Y;
	a = x1;
	while (a <= x2)
	{	
		mlx_pixel_put(map.mlx, map.win, BEGIN_X + map.LR + a * map.zoom, BEGIN_Y + map.UD + (y1 + ((y2 - y1) * (a - x1)) / (x2 - x1)) * map.zoom, 0xFFFFFF);
		a += 0.01;
	}
}

void 	ft_draw_to_D(t_env map, int j, int i)
{
	float 	a;
	float 	x1;
	float 	x2;
	float 	y1;
	float 	y2;

	x1 = map.tab[i][j].X;
	x2 = map.tab[i + 1][j].X;
	y1 = map.tab[i][j].Y;
	y2 = map.tab[i + 1][j].Y;
	a = y1;
	if (a > y2)
	{
		while (a > y2)
		{
			mlx_pixel_put(map.mlx, map.win, BEGIN_X  + map.LR + (x1 + ((x2 - x1) * (a - y1)) / (y2 - y1)) * map.zoom, BEGIN_Y + map.UD + a * map.zoom, 0xFFFFFF);
			a -= 0.01;
		}
	}
	while (a <= y2)
	{
		mlx_pixel_put(map.mlx, map.win, BEGIN_X + map.LR + (x1 + ((x2 - x1) * (a - y1)) / (y2 - y1)) * map.zoom, BEGIN_Y + map.UD + a * map.zoom, 0xFFFFFF);
		a += 0.01;
	}
}

void	ft_draw_map(t_env map)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (i < map.y)
	{
		while (j < map.x)
		{
			if (i < map.y - 1)
				ft_draw_to_D(map, j, i);
			mlx_pixel_put(map.mlx, map.win, BEGIN_X + map.LR + map.tab[i][j].X * map.zoom, BEGIN_Y + map.UD + map.tab[i][j].Y * map.zoom, 0xFFFFFF);
			if (j < map.x - 1)
				ft_draw_to_R(map, j, i);
			j++;
		}
	j = 0;
	i++;
	}
}