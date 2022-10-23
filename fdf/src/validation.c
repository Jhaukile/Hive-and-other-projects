/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:33:27 by jhaukile          #+#    #+#             */
/*   Updated: 2022/06/13 14:58:16 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit((int)str[i]) == 0 && str[i] != ' ' && str[i] != '-')
			ft_exit("error");
		if (str[i] == '-' && str[i + 1] == '-')
			ft_exit("error");
		i++;
	}
}

void	ft_gnl_validate(char *file)
{
	char	*line;
	int		col;
	int		fd;

	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) == 0)
		ft_exit("error");
	if (line == NULL)
		ft_exit("error");
	ft_check_char(line);
	col = ft_width(line);
	if (col == 0)
		ft_exit("error");
	free(line);
	while (get_next_line(fd, &line))
	{
		ft_check_char(line);
		if (ft_width(line) != col)
			ft_exit("error");
		free(line);
	}
	close(fd);
}

int	ft_width(char *str)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
		{
			i++;
			if (ft_isdigit((int)str[i]) == 0)
				ft_exit("error");
		}
		if (ft_isdigit((int)str[i]) == 1)
		{
			width++;
			i++;
			while (ft_isdigit((int)str[i]) == 1)
				i++;
		}
	}
	return (width);
}

void	ft_check_map(char *file, t_fdf *data)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (data->height == 0)
			data->width = ft_width(line);
		data->height++;
		free(line);
	}
	close(fd);
}
