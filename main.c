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

int		main(void)
{
	void	*mlx;
	void	*win;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	mlx_loop(mlx);
	return (0);
}
