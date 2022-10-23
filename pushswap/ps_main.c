/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:28:35 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:28:36 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_algorithms	select_sorting_alg(t_int_arr *stack_a,
		t_int_arr stack_b, t_instructions *instr)
{
	if (stack_a[0].size == 3)
	{
		simple_sort(stack_a[SIMPLE], &instr[SIMPLE]);
		return (SIMPLE);
	}
	select_sort(stack_a[SELECT], stack_b, &instr[SELECT]);
	radix_sort(stack_a[RADIX], stack_b, &instr[RADIX]);
	if (instr[RADIX].size < instr[SELECT].size)
		return (RADIX);
	return (SELECT);
}

void	free_all(t_int_arr *stack_a, t_instructions *instr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free_2d_arr(instr[i].instr, instr[i].space);
		ft_memdel((void **)&stack_a[i].arr);
		i++;
	}
}

static void	at_exit(t_instructions *instr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free_2d_arr(instr[i].instr, instr[i].space);
		i++;
	}
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_int_arr		stack_b;
	t_instructions	instr[3];
	t_int_arr		stack_a[3];

	if (argc < 2)
		return (0);
	init_all_instructions(instr);
	if (initialize_arrays(&stack_a[0], argv, argc) == -1)
		at_exit(instr);
	stack_b.size = 0;
	stack_b.arr = (int *)ft_memalloc(sizeof(int) * stack_a[0].size);
	if (!stack_b.arr)
		exit(-1);
	output_instructions(&instr[select_sorting_alg(stack_a, stack_b, instr)]);
	free_all(stack_a, instr);
	ft_memdel((void **)&stack_b.arr);
	return (0);
}
