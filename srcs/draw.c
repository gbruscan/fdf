#include "fdf.h"

void 	ft_draw_to_R(t_env map, t_coord **tab, int j, int i)
{
	float 	a;
	float 	x1;
	float 	x2;
	float 	y1;
	float 	y2;

	x1 = tab[i][j].X;
	x2 = tab[i][j + 1].X;
	y1 = tab[i][j].Y;
	y2 = tab[i][j + 1].Y;
	a = x1;
	while (a <= x2)
	{	
		mlx_pixel_put(map.mlx, map.win, BEGIN_X + a * 20, BEGIN_Y + (y1 + ((y2 - y1) * (a - x1)) / (x2 - x1)) * 20, 0xFFFFFF);
		a += 0.01;
	}
}

void 	ft_draw_to_D(t_env map, t_coord **tab, int j, int i)
{
	float 	a;
	float 	x1;
	float 	x2;
	float 	y1;
	float 	y2;

	x1 = tab[i][j].X;
	x2 = tab[i + 1][j].X;
	y1 = tab[i][j].Y;
	y2 = tab[i + 1][j].Y;
	a = y1;
	while (a < y2)
	{
		mlx_pixel_put(map.mlx, map.win, BEGIN_X + (x1 + ((x2 - x1) * (a - y1)) / (y2 - y1)) * 20, BEGIN_Y + a * 20, 0xFFFFFF);
		a += 0.01;
	}
}

void	ft_draw_map(t_env map, t_coord **tab)
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
				ft_draw_to_D(map, tab, j, i);
			mlx_pixel_put(map.mlx, map.win, BEGIN_X + tab[i][j].X * 20, BEGIN_Y + tab[i][j].Y * 20, 0xFFFFFF);
			ft_draw_to_R(map, tab, j, i);
			j++;
		}
	j = 0;
	i++;
	}
}