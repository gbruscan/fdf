/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:16:10 by gbruscan          #+#    #+#             */
/*   Updated: 2016/01/12 14:04:39 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_create_buff(char *buff, int j)
{
	char	*tmp;
	int		size;

	size = ft_strlen((const char *)buff);
	tmp = (char *)malloc(sizeof(char) * (size - j));
	if (tmp == NULL)
		return (-1);
	ft_strcpy(tmp, (const char *)(buff + j + 1));
	ft_bzero(buff, size);
	ft_strcpy(buff, tmp);
	if (tmp)
		free(tmp);
	return (1);
}

int		ft_get_new_line(char *buff, char **line, int j)
{
	char	*s1;
	char	*s2;

	s1 = *line;
	s2 = (char *)malloc(sizeof(char) * (j + ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (-1);
	ft_strcpy(s2, s1);
	ft_strncat(s2, buff, j);
	*line = s2;
	if (s1)
		free(s1);
	return (ft_create_buff(buff, j));
}

int		ft_buff_cpy(char *buff, char **line)
{
	char	*s1;
	char	*s2;

	s1 = *line;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (-1);
	ft_strcpy(s2, s1);
	ft_strcat(s2, buff);
	*line = s2;
	if (s1)
		free(s1);
	ft_bzero(buff, ft_strlen(buff));
	return (2);
}

int		ft_line_status(char *buff, char **line)
{
	int		j;

	j = 0;
	while (buff[j] != '\n' && buff[j] != 0)
		j++;
	if (buff[j] == 0)
		return (ft_buff_cpy(buff, line));
	else
		return (ft_get_new_line(buff, line, j));
}

int		get_next_line(int const fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	int			ret;
	int			gnl;

	if (line == NULL)
		return (-1);
	*line = ft_strdup("");
	gnl = 2;
	while (gnl == 2)
	{
		if (buff[0] == 0)
		{
			if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
				return (-1);
			if (ret > 0)
				buff[ret] = 0;
			if (ret == 0 && buff[0] != 0)
				return (ft_get_new_line(buff, line, 0));
			if (ret == 0)
				return (0);
		}
		gnl = ft_line_status(buff, line);
	}
	return (gnl);
}
