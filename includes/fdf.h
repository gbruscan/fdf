#ifndef FDF_H
# define FDF_H

#include "get_next_line.h"
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
# define SPACE 500
# define BEGIN_X 550
# define BEGIN_Y 500

typedef struct 	s_env
{
	int 		x;
	int 		y;
	int 		**map;
	void 		*mlx;
	void 		*win;
	float 		b;
}				t_env;

typedef struct 	s_coord
{
	float 		X;
	float 		Y;
}				t_coord;

int 	ft_error(void);
int		ft_check_line(char *line);
int		ft_check_map(int fd);
int		ft_color_checker(char *line, int i);
int		ft_ishexa(char c);
int		ft_map(int fd);
int		ft_increase_j(char *line, int j);
int 	ft_how_much_int(char *line);
int		*ft_strdup_atoi(char *line, int *x);
void	ft_window(t_env map);
void	ft_draw_map(t_env map, t_coord **tab);
float 	ft_Y(float x, float y, int z);
float 	ft_X(float x, float y);
float 	ft_get_Y(t_env map, float a);
t_env 	ft_fill_map(int fd, int m);

#endif