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

/*int		main(void)
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
	int **map;

	if (argc != 2)
	{	
		ft_putendl("error");	
		return (0);		
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		{
			ft_putendl("error");
			return (0);
		}
	if (ft_check_map(fd) == 0)
		return (0);
	close (fd);
	fd = open(argv[1], O_RDONLY);
	map = ft_fill_map(fd);
	return (0);
}