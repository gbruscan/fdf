#include "fdf.h"

int 	ft_how_much_int(char *line)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-'))
		{
			j += 1;
			while ((line[i] == '-') || (line[i] >= '0' && line[i] <= '9'))
				i++;
		}
		if (line[i] == ',')
			i += 9;
		while (line[i] == ' ')
			i++;
	}
	return (j);
}

int		ft_increase_j(char *line, int j)
{
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	while (line[j] == ' ' && line[j] != '\0')
		j++;
	return (j);
}

int		*ft_strdup_atoi(char *line)
{
	int		i;
	int		j;
	int		*map;

	i = 0;
	j = 0;
	map = (int *)malloc(sizeof(int) * ft_how_much_int(line));
	if (!map)
		return (NULL);
	while (line && line[j] != '\0')
	{
		map[i] = ft_atoi(line + j);
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
		map[i] = ft_strdup_atoi(line); 
		i++;
	}
	return (map);
}