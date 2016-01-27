#include "fdf.h"

int		ft_check_line(char *line)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
		{
			j = ft_color_checker(line, i + 1);
			if (j == 1)
				i += 8;
			else
				return (0);
		}
		else if ((line[i] < '0' || line[i] > '9') && (line[i] != '-' && line[i] != ' '))
				return (0);	
		i++;
	}
	return (1);
}

int		ft_check_map(int fd)
{
	char	*line;
	int		z;

	while (get_next_line(fd, &line))
	{
		z = ft_check_line(line);
		if (z == 0)
			{
				ft_putendl("invalid map");
				return (0);
			}
	}
	return (1);
}