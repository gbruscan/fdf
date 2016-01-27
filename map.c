#include "fdf.h"

int	ft_map(int fd)
{
	int		m;
	char	*line;

	m = 0;
	line = NULL;
	while (get_next_line(fd, &line))
		m++;
	if (ft_strcmp(line, "") != 0)
		m += 1;
	printf("%d\n", m);
	return (m);
}



int **ft_fill_map(int fd)
{
	int 	**map;
	int 	m;

	map = NULL;
	m = ft_map(fd);
	return (map);
}