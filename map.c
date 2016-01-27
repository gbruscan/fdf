#include "fdf.h"

int		ft_increase_j(char *line, int j)
{
	while (line[j] != ' ')
		j++;
	return (j);
}

int		*ft_strdup_atoi(int *map, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[j] != '\0')
	{
		map[i] = ft_atoi(line + j);
		ft_putnbr(map[i]);
		ft_putchar('\n');
		i += 1;
		j = ft_increase_j(line, j);
	}
	return (map);
}

int		ft_map(int fd)
{
	int		m;
	char	*line;

	m = 0;
	line = NULL;
	while (get_next_line(fd, &line))
		m++;
	if (ft_strcmp(line, "") != 0)
		m += 1;
	return (m);
}



int 	**ft_fill_map(int fd, int m)
{
	int 	i;
	int 	**map;
	char 	*line;

	i = 0;
	line = NULL;
	map = (int **)malloc(sizeof(int *) * m);
	if (!map)
		return (0);
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup_atoi(map[i], line); 
		i++;
	}
	return (map);
}