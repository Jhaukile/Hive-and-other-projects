/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:16:20 by jhaukile          #+#    #+#             */
/*   Updated: 2022/06/17 13:54:42 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_fdf
{
	void		*win_ptr;
	void		*mlx_ptr;
	float		x;
	float		y;
	float		x1;
	float		y1;
	float		z;
	float		z1;
	int			height;
	int			width;
	id_t		color;
	int			**crd;
	int			zoom;
	float		vert;
	float		hori;
	float		isox;
	float		isoy;
	float		h;
	int			isometric;
}				t_fdf;

# define TEXT_COLOR			0xEAEAEA

void	ft_read_file(char *file, t_fdf *data);
void	ft_split_atoi(int *xyz, char *line);
void	ft_check_map(char *file, t_fdf *data);
int		ft_width(char *str);
void	ft_checkmax(t_fdf *data);
void	ft_bresenham(float x, float y, t_fdf *data);
void	ft_draw_lines(float x, float y, t_fdf *data);
void	ft_check_char(char *str);
void	ft_gnl_validate(char *file);
int		deal_key(int key, t_fdf *data);
void	key_color(int key, t_fdf *data);
void	key_isometric(int key, t_fdf *data);
void	key_move(int key, t_fdf *data);
void	ft_default(t_fdf *data);
void	print_menu(t_fdf *fdf);

#endif