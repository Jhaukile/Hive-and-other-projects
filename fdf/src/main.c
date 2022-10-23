/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:22:01 by jhaukile          #+#    #+#             */
/*   Updated: 2022/06/17 17:17:51 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_split_atoi(int *crd, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
	{
		crd[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
		i++;
	}
	free (tmp);
}

void	ft_read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	ft_check_map(file, data);
	fd = open(file, O_RDONLY);
	if (fd == 0)
		ft_exit("error");
	i = 0;
	data->crd = (int **)malloc(sizeof(int *) * data->height);
	while (i < data->height)
			data->crd[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	i = 0;
	while (get_next_line(fd, &line) > 0 && i < data->height)
	{
		ft_split_atoi(data->crd[i], line);
		i++;
		free(line);
	}
	close(fd);
}

void	ft_default(t_fdf *data)
{
	data->zoom = 30;
	data->vert = 550;
	data->hori = 400;
	data->isox = 1;
	data->isoy = 1;
	data->color = 0xff0000;
	data->h = 5;
	data->isometric = 1;
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (data == NULL)
		ft_exit("error");
	data->mlx_ptr = mlx_init();
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf	target_file");
		return (0);
	}
	ft_default(data);
	ft_gnl_validate(argv[1]);
	ft_read_file(argv[1], data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "fdf");
	ft_checkmax(data);
	print_menu(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
