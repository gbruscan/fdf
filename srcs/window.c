#include "fdf.h"

t_env 	ft_init_hooks(t_env map)
{
	map.zoom = 5;
	map.LR = 0;
	map.UD = 0;
	map.redraw = 1;
	return (map);
}

float 	ft_X(float x, float y)
{
	float 	X;

	X = (1.6 * x) - (1.4 * y);
	return (-X);
}

float 	ft_Y(float x, float y, int z)
{
	float 	Y;

	Y = (-z / 4) + (0.8 * x) + (0.7 * y);
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
		tab[j].X = ft_X(i, j);
		tab[j].Y = ft_Y(i, j, map.map[i][j]);
		j++;
	}
	return (tab);
}

void	ft_window(t_env map)
{
	int 		i;

	i = 0;
	map.tab = (t_coord **)malloc(sizeof(t_coord *) * map.y);
	while (i < map.y)
	{
		map.tab[i] = ft_fill_tab(map.tab[i], map, i);
		i++;
	}
	map = ft_init_hooks(map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1200, 1200, "fdf");
	mlx_loop_hook(map.mlx, ft_expose_hook, &map);
	mlx_hook(map.win, 2, 0, ft_key_funct, &map);
	mlx_loop(map.mlx);
}