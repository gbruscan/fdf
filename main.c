/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:55:20 by gbruscan          #+#    #+#             */
/*   Updated: 2016/01/20 18:04:28 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(int **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 11)
	{
		while (j < 19)
		{
			ft_putnbr(map[i][j]);
			ft_putstr("  ");
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

int 	ft_error(void)
{
	ft_putendl("error");
	return (0);
}

int 	main(int argc, char **argv)
{
	int 	fd;
	int 	m;
	t_env 	map;

	if (argc != 2)
		return (ft_error());
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error());
	if (ft_check_map(fd) == 0)
		return (0);
	close (fd);
	fd = open(argv[1], O_RDONLY);
	m = ft_map(fd);
	close (fd);
	fd = open(argv[1], O_RDONLY);
	map.map = ft_fill_map(fd, m);
	ft_print_map(map.map);
//	ft_window(map);
	return (0);
}