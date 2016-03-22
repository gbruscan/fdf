#include "fdf.h"

void 	ft_draw_line(t_env map, int j, int i)
{
	float 	a;
	float 	y1;
	float 	y2;

	a = j;
	y1 = i;
	while (a < SPACE)
	{	
		y2 = ft_get_Y(map, a);
		mlx_pixel_put(map.mlx, map.win, BEGIN_X + a, BEGIN_Y + y1 + ((y2 - y1) * (a - j) / (map.x - j)), 0xFFFFFF);
		a += 0.01;
		y1 = y2;
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
			mlx_pixel_put(map.mlx, map.win, BEGIN_X + tab[i][j].X * 20, BEGIN_Y + tab[i][j].Y * 20, 0xFFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
}