/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:22:43 by jhaukile          #+#    #+#             */
/*   Updated: 2022/06/17 13:53:46 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "change isometric:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "numpad 2468");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "colors: G-R-B");
}
