#include "fdf.h"

t_env 	ft_init_hooks(t_env map)
{
	map.LR = 0;
	map.UD = 0;
	map.redraw = 1;
	map.cte1 = 1.6;
	map.cte2 = 0.8;
	map.alt = 4;
	if (map.x * map.y <= 500)
		map.zoom = 20;
	else if (map.x * map.y > 500 && map.x * map.y <= 2000)
		map.zoom = 10;
	else
		map.zoom = 2.4;
	map.zoom_save = map.zoom;
	return (map);
}

float 	ft_X(t_env map, float x, float y)
{
	float 	X;

	X = (map.cte1 * x) - (1.4 * y);
	return (-X);
}

float 	ft_Y(t_env map, float x, float y, int z)
{
	float 	Y;

	Y = (-z / map.alt) + (map.cte2 * x) + (0.6 * y);
	return (Y);
}

t_coord	*ft_fill_tab(t_coord *tab, t_env map, int i)
{
	int 		j;

	j = 0;
	tab = (t_coord *)malloc(sizeof(t_coord) * map.x);
	if (!tab)
		return (NULL);
	while (j < map.x)
	{
		tab[j].X = ft_X(map, i, j);
		tab[j].Y = ft_Y(map, i, j, map.map[i][j]);
		j++;
	}
	return (tab);
}
#include <stdio.h>
void	ft_window(t_env map)
{
	int 		i;

	i = 0;
	map = ft_init_hooks(map);
	map.tab = (t_coord **)malloc(sizeof(t_coord *) * map.y);
	while (i < map.y)
	{
		map.tab[i] = ft_fill_tab(map.tab[i], map, i);
		i++;
	}
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1200, 1200, "fdf");
	mlx_loop_hook(map.mlx, ft_expose_hook, &map);
	mlx_hook(map.win, 2, 0, ft_key_funct, &map);
	mlx_loop(map.mlx);
}