/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:34:00 by jhaukile          #+#    #+#             */
/*   Updated: 2022/06/14 12:54:49 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_calc_max(int a, int b)
{
	int		aa;
	int		bb;

	aa = a;
	bb = b;
	if (aa < 0)
		a *= -1;
	if (bb < 0)
		b *= -1;
	if (a > b)
		return (a);
	return (b);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->isox);
	*y = (*x + *y) * sin(data->isoy) - z;
}

void	ft_draw_lines(float x, float y, t_fdf *data)
{
	float	x_line;
	float	y_line;
	int		max;
	int		color;

	x_line = data->x1 - x;
	y_line = data->y1 - y;
	max = ft_calc_max(x_line, y_line);
	x_line /= max;
	y_line /= max;
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		color = mlx_get_color_value(data->mlx_ptr, data->color + data->z1);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + data->vert,
			y + data->hori, 0xffffff);
		if (data->z != 0)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + data->vert,
				y + data->hori, color);
		x += x_line;
		y += y_line;
	}
}

void	ft_bresenham(float x, float y, t_fdf *data)
{
	data->z = data->crd[(int)y][(int)x] * data->h;
	data->z1 = data->crd[(int)data->y1][(int)data->x1] * data->h;
	x *= data->zoom;
	y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	if (data->isometric == 1)
	{
		isometric(&x, &y, data->z, data);
		isometric(&data->x1, &data->y1, data->z1, data);
	}
	ft_draw_lines(x, y, data);
}

void	ft_checkmax(t_fdf *data)
{
	float	x;
	float	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				data->x1 = x + 1;
				data->y1 = y;
				ft_bresenham(x, y, data);
			}
			if (y < data->height - 1)
			{
				data->x1 = x;
				data->y1 = y + 1;
				ft_bresenham(x, y, data);
			}
			x++;
		}
		y++;
	}
}
