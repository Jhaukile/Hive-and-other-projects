/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:18:33 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:18:35 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	instruction_swap(const char *instruction,
				t_int_arr *a, t_int_arr *b)
{
	if (ft_strcmp(instruction, "sa") == 0)
		stack_swap(&a->arr[0], &a->arr[1], a->size);
	else if (ft_strcmp(instruction, "sb") == 0)
		stack_swap(&b->arr[0], &b->arr[1], b->size);
	else if (ft_strcmp(instruction, "ss") == 0)
	{
		stack_swap(&a->arr[0], &a->arr[1], a->size);
		stack_swap(&b->arr[0], &b->arr[1], b->size);
	}
	else if (ft_strcmp(instruction, "pa") == 0)
		stack_push(a, stack_pop(b));
	else if (ft_strcmp(instruction, "pb") == 0)
		stack_push(b, stack_pop(a));
}

static void	instruction_rotate(const char *instruction,
				t_int_arr *a, t_int_arr *b)
{
	if (ft_strcmp(instruction, "ra") == 0)
		stack_rotate(a);
	else if (ft_strcmp(instruction, "rb") == 0)
		stack_rotate(b);
	else if (ft_strcmp(instruction, "rr") == 0)
	{
		stack_rotate(a);
		stack_rotate(b);
	}
	else if (ft_strcmp(instruction, "rra") == 0)
		stack_reverse_rotate(a);
	else if (ft_strcmp(instruction, "rrb") == 0)
		stack_reverse_rotate(b);
	else if (ft_strcmp(instruction, "rrr") == 0)
	{
		stack_reverse_rotate(a);
		stack_reverse_rotate(b);
	}
}

void	execute_instructions(char **instructions, t_int_arr *a, t_int_arr *b)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		if (instructions[i][0] == 'r')
			instruction_rotate(instructions[i], a, b);
		else
			instruction_swap(instructions[i], a, b);
		i++;
	}
}
