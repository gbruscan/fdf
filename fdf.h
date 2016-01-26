#ifndef FDF_H
# define FDF_H

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>

int		ft_check_line(char *line);
int		ft_check_map(int fd);
int		ft_color_checker(char *line, int i);
int		ft_ishexa(char c);

#endif