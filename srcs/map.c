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

int		*ft_strdup_atoi(char *line, int *x)
{
	int		i;
	int		j;
	int		*map;

	i = 0;
	j = 0;
	map = (int *)malloc(sizeof(int) * ft_how_much_int(line));
	if (!map)
		return (NULL);
	*x = ft_how_much_int(line);
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

t_env	ft_fill_map(int fd, int m)
{
	int 	i;
	char 	*line;
	t_env	map;

	i = 0;
	line = NULL;
	map.x = 0;
	map.y = m;
	map.map = (int **)malloc(sizeof(int *) * m);
	while (get_next_line(fd, &line))
	{
		map.map[i] = ft_strdup_atoi(line, &map.x); 
		i++;
	}
	return (map);
}