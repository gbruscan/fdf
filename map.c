#include "fdf.h"

char **ft_fill_map(int fd);
{
	char **map;
	char *line;
	int i;

	map = NULL;
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line)
		ft_putendl(map[i]);
		i++;
	}
	return (map);
}