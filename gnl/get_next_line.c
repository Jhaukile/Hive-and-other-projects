/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 07:30:38 by jhaukile          #+#    #+#             */
/*   Updated: 2021/12/29 15:37:36 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_line(char **save, char **line, int i)
{
	char	*temp;

	while ((*save)[i] != '\0' && (*save)[i] != '\n')
		i++;
	if ((*save)[i] == '\n')
	{
		*line = ft_strsub(*save, 0, i);
		if (!line)
			free(*save);
		if (!line)
			return (-1);
		temp = ft_strdup(&((*save)[i + 1]));
		free(*save);
		if (!temp)
			return (-1);
		*save = temp;
		if ((**save) == '\0')
			ft_strdel(save);
		return (1);
	}
	*line = ft_strdup(*save);
	ft_strdel(save);
	if (!*line)
		return (-1);
	return (1);
}

static int	ft_buffer_save(char **save, char *buf)
{
	char	*temp;

	if (*save)
	{
		temp = ft_strjoin(*save, buf);
		free(*save);
		if (!temp)
			return (-1);
		*save = temp;
		return (1);
	}
	*save = ft_strdup(buf);
	if (!*save)
		return (-1);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*save[MAX_FD];
	int			read_output;

	if (fd < 0 || fd >= 4096 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (save[fd])
		if (ft_strchr(save[fd], '\n'))
			return (ft_line(&save[fd], line, 0));
	read_output = 1;
	while (read_output)
	{
		read_output = read(fd, buf, BUFF_SIZE);
		if (read_output < 0)
			return (-1);
		if (read_output == 0 && !save[fd])
			return (0);
		buf[read_output] = '\0';
		if (ft_buffer_save(&save[fd], buf) == -1)
			return (-1);
		if (save[fd])
			if (ft_strchr(save[fd], '\n'))
				break ;
	}
	return (ft_line(&save[fd], line, 0));
}
