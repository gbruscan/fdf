#include "fdf.h"

int		ft_ishexa(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	if (c >= 'a' && c <= 'f')	
		return (1);
	return (0);
}

int		ft_color_checker(char *line, int i)
{
	int	number;
	int	k;

	number = 0;
	k = 0;

	if (line[i] == '0')
		i += 1;
	else
		return (0);
	if (line[i] == 'x')
		i += 1;
	else
		return (0);
	while (ft_ishexa(line[i]))
	{
		if (line[i] >= '0' && line[i] <= '9')
			number = number * 16 + line[i] - '0';
		if (line[i] >= 'A' && line[i] <= 'F')
			number = number * 16 + line[i] - '7';
		if (line[i] >= 'a' && line[i] <= 'f')
			number = number * 16 + line[i] - 'W';
		k += 1;
		i++;
	}
	if (number >= 0 && number <= 16777215 && k == 6)
		return (1);
	return (0);
}
