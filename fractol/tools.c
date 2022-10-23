/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:34:41 by jhaukile          #+#    #+#             */
/*   Updated: 2022/09/27 11:51:35 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color(t_t *t, int color)
{
	t->index = (4 * 1000 * t->y_y) + t->x_x * 4;
	t->ch[t->index] = (t->itier * t->color + 680 + 179) * color;
	t->ch[t->index + 1] = (t->itier * t->color + 42 + 84) * color;
	t->ch[t->index + 2] = (t->itier * t->color + 936 + 45) * color;
	t->ch[t->index + 3] = 0;
}

double	ft_doubleabs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	map(t_t *t)
{
	t->x = t->x_x / (WIDTH / (t->end_x - t->start_x)) + t->start_x;
	t->y = t->y_y / (HEIGHT / (t->end_y - t->start_y)) + t->start_y;
	t->x_o = t->x;
	t->y_o = t->y;
}

void	itier_loop(t_t *t)
{
	while (t->itier < t->max)
	{
		t->xtmp = t->x * t->x - t->y * t->y;
		if (ft_strcmp(t->name, "Burningship") == 0)
			t->ytmp = ft_doubleabs(2 * t->x * t->y);
		else
			t->ytmp = 2 * t->x * t->y;
		t->x = t->xtmp + t->x_o;
		t->y = t->ytmp + t->y_o;
		if (t->x * t->x + t->y * t->y > 4)
			break ;
		t->itier++;
	}
}
