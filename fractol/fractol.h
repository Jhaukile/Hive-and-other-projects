/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:34:59 by jhaukile          #+#    #+#             */
/*   Updated: 2022/09/27 12:08:45 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FRACTOL_H
#	define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
# include "libft/libft.h"

#	define WIDTH 600
#	define HEIGHT 600

typedef struct		s_t
{
	unsigned char	*ch;
	double			x;
	double			y;
	double			x_x;
	double			y_y;
	void			*ptr;
	void			*win;
	double			x_o;
	double			y_o;
	int				itier;
	double			xtmp;
	double			ytmp;
	void			*image;
	int				size_line;
	int				bitspp;
	int				endian;
	int				index;
	char			*name;
	double			start_y;
	double			end_y;
	double			start_x;
	double			end_x;
	int				zoom;
	int				stop;
	int				max;
	int				color;

}					t_t;

void				mandelbrot(t_t *t);
int					mouse_move(int x, int y, t_t *t);
int					mouse_press(int button, int x, int y, t_t *t);
int					key_press(int keycode, t_t *t);
int					key_press(int keycode, t_t *t);
void				julia(t_t *t);
void				menu(t_t *t);
void				itier_loop(t_t *t);
void				map(t_t *t);
double				ft_doubleabs(double n);
void				key_press2(int keycode, t_t *t);
void				key_press3(int keycode, t_t *t);
void				key_press4(int keycode, t_t *t);
void				set_color(t_t *t, int color);
int					str_cmp(char *s1, char *s2);
void				check_ar(t_t *t);
void				init(t_t *t, char *str);
void				string_put(t_t *t);
void				zoom(t_t *t, double x, double y, double zoom);
void				mlx_ho(t_t *t);
void				simple_zoome1(t_t *t);
void				simple_zoome2(t_t *t);
void				init_x_y(t_t *t);
void				string1_put(t_t *t);
void				destroy_exit(t_t *t);

#	endif