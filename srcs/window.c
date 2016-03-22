#include "fdf.h"

float 	ft_get_b(t_env map)
{
	float b;

	if (map.x < map.y)
		b = map.y;
	else
		b = map.x;
	return (b);
}

float 	ft_get_Y(t_env map, float a)
{
	float 	f;

	f = (a / map.x) * map.y;
	return (f);
}

float 	ft_X(float x, float y)
{
	float 	X;

	X = (0.9 * x) - (0.8 * y);
	return (-X);
}

float 	ft_Y(float x, float y, int z)
{
	float 	Y;

	Y = (-z / 5) + (0.45 * x) + (0.4 * y);
	return (Y);
}

int 	ft_key_funct(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
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
	t_coord		**tab;
	int 		i;

	i = 0;
	tab = (t_coord **)malloc(sizeof(t_coord *) * map.y);
	while (i < map.y)
	{
		tab[i] = ft_fill_tab(tab[i], map, i);
		i++;
	}
	map.b = ft_get_b(map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1200, 1200, "fdf");
	ft_draw_map(map, tab);
	mlx_key_hook(map.win, *ft_key_funct, 0);
	mlx_loop(map.mlx);
}
