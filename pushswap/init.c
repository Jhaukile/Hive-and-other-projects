/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:24:51 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 15:24:53 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	initialize_arrays(t_int_arr *stack_a, char **argv, int argc)
{
	t_algorithms	i;
	t_arguments		arg;

	arg = fix_arguments(argc - 1, &argv[1]);
	if (!validate_arguments(arg.argc, arg.argv))
	{
		free_2d_arr(arg.argv, arg.argc);
		return (-1);
	}
	i = SELECT;
	while (i < 3)
	{
		stack_a[i] = simple_array(make_int_array(arg.argc, arg.argv));
		if (stack_a[i].size == 0)
		{
			free_2d_arr(arg.argv, arg.argc);
			return (-1);
		}
		i++;
	}
	free_2d_arr(arg.argv, arg.argc);
	return (0);
}

void	init_all_instructions(t_instructions *instr)
{
	t_algorithms	i;

	i = SELECT;
	while (i < 3)
	{
		init_instructions(&instr[i]);
		i++;
	}
}
