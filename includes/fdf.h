#ifndef FDF_H
# define FDF_H

#include "get_next_line.h"
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
# define BEGIN_X 550
# define BEGIN_Y 400

typedef struct 	s_coord
{
	float 		X;
	float 		Y;
}				t_coord;

typedef struct 	s_env
{
	int 		x;
	int 		y;
	int 		**map;
	int 		LR;
	int 		UD;
	int 		redraw;
	int 		alt;
	void 		*mlx;
	void 		*win;
	float 		zoom;
	float 		cte1;
	float 		cte2;
	t_coord		**tab;
}				t_env;

int 	ft_error(void);
int		ft_check_line(char *line);
int		ft_check_map(int fd);
int		ft_color_checker(char *line, int i);
int		ft_ishexa(char c);
int		ft_map(int fd);
int		ft_increase_j(char *line, int j);
int 	ft_how_much_int(char *line);
int		*ft_strdup_atoi(char *line, int *x);
int 	ft_key_funct(int keycode, t_env *map);
int		ft_expose_hook(t_env *map);
void	ft_window(t_env map);
void	ft_draw_map(t_env map);
float 	ft_Y(t_env map, float x, float y, int z);
float 	ft_X(t_env map, float x, float y);
t_env 	ft_fill_map(int fd, int m);

#endif