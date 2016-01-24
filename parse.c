#include "fdf.h"

int			ft_getnbr(char *s)
{
	int		res;

	res = 0;
	while ((*s >= '0') && (*s <= '9'))
		res = (res * 10) + *s++ - '0';
	return (res);
}

int		ft_check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] < '0' || line[i] > '9') && (line[i] != '-' && line[i] != ' '))
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
//		ft_putendl(line);
		if (z == 0)
			{
				ft_putendl("invalid map");
				return (0);
			}
	}
	return (1);
}