#ifndef FDF_H
# define FDF_H

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
# define SPACE 1000
# define BEGIN 150

typedef struct 	s_env
{
	int 		x;
	int 		y;
	int 		**map;
	void 		*mlx;
	void 		*win;
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
void	ft_window(t_env map);
t_env 	ft_fill_map(int fd, int m);

#endif