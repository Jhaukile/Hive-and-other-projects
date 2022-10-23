/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:36:07 by jhaukile          #+#    #+#             */
/*   Updated: 2022/09/27 12:25:29 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	simple_zoome1(t_t *t)
{
	if (t->start_x < 0 && t->start_y < 0 && t->end_x > 0 && t->end_y > 0)
	{
		t->start_x = t->start_x + 0.015;
		t->start_y = t->start_y + 0.015;
		t->end_x = t->end_x - 0.015;
		t->end_y = t->end_y - 0.015;
	}
}

void	simple_zoome2(t_t *t)
{
	t->start_x = t->start_x - 0.040;
	t->start_y = t->start_y - 0.040;
	t->end_x = t->end_x + 0.040;
	t->end_y = t->end_y + 0.040;
}

void	init_x_y(t_t *t)
{
	t->x = ((t->x_x / (double)WIDTH) * \
	(t->end_x - t->start_x)) + t->start_x;
	t->y = ((t->y_y / (double)HEIGHT) * \
	(t->end_y - t->start_y)) + t->start_y;
}

void	string1_put(t_t *t)
{
	mlx_string_put(t->ptr, t->win, 650, 10, 0xFFFFFF,
		"ZOOM");
	mlx_string_put(t->ptr, t->win, 650, 40, 0xf7b079,
		"+ | -");
	mlx_string_put(t->ptr, t->win, 650, 500, 0xFFFFFF,
		"Iteration");
	mlx_string_put(t->ptr, t->win, 650, 520, 0xf7b079,
		"+ | -");
}

void	destroy_exit(t_t *t)
{
	mlx_destroy_image(t->ptr, t->image);
	mlx_destroy_window(t->ptr, t->win);
	free(t->ptr);
}
