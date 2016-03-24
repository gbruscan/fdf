#include "fdf.h"

int		ft_expose_hook(t_env *map)
{
	if (map->redraw == 1)
	{
    	mlx_clear_window (map->mlx, map->win);
		ft_draw_map(*map);
	}
	map->redraw = 0;
	return (0);
}

void 	ft_move_funct(int keycode, t_env *map)
{
	if (keycode == 123)
		map->LR -= 10;
	else if (keycode == 124)
		map->LR += 10;
	else if (keycode == 125)
		map->UD += 10;
	else if (keycode == 126)
		map->UD -= 10;
}

int 	ft_key_funct(int keycode, t_env *map)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		ft_move_funct(keycode, map);
	else if (keycode == 78)
		map->zoom -= 1;
	else if (keycode == 69)
		map->zoom += 1;
	else if (keycode == 82)
		map->zoom = map->zoom_save;
	map->redraw = 1;
	return (0);
}