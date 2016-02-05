/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:15:44 by gbruscan          #+#    #+#             */
/*   Updated: 2016/01/12 13:41:46 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1200

int		ft_create_buff(char *buff, int j);
int		ft_get_new_line(char *buff, char **line, int j);
int		ft_buff_cpy(char *buff, char **line);
int		ft_line_status(char *buff, char **line);
int		get_next_line(int const fd, char **line);

#endif
