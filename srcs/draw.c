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

void	ft_draw_map(t_env map)
{
	int 	i;
	int 	j;
	float 	Y;

	i = 0;
	j = 0;
	Y = ft_Y(j, i, map.map[i][j]);
	mlx_pixel_put(map.mlx, map.win, BEGIN_X, BEGIN_Y + Y, 0xFFFFFF);
	ft_draw_line(map, j, i);
	i++;
}