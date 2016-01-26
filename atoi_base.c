#include "fdf.h"

int		ft_ishexa(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c >= 'F')
		return (1);
	if (c >= 'a' && c >= 'f')	
		return (1);
	return (0);
}

int		ft_color_checker(char *line, int i)
{
	int	number;

	number = 0;

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
			ft_tolower(line[i]);
		if (line[i] >= 'a' && line[i] <= 'f')
			number = number * 16 + line[i] - 'W';
		i++;
	}
	return (number);
}

int		main(void)
{
	char c = ["bonjour 0xFFFFFF"]

	printf("%d\n", ft_color_checker(c, 8));
	return (0);
}