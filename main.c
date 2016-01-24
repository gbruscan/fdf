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

#include <mlx.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*int			ft_getnbr(char *s)
{
	int		res;

	res = 0;
	while ((*s >= '0') && (*s <= '9'))
		res = (res * 10) + *s++ - '0';
	return (res);
}

int		main(void)
{
	void	*mlx;
	void	*win;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	mlx_loop(mlx);
	return (0);
}
*/

int 	main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{	
		ft_putendl("error");	
		return (0);		
	}
	fd = open("argv[1]", O_RDONLY);
	get_next_line(fd, argv);
	return (0);
}