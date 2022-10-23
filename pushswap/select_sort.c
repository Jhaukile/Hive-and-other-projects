/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:37:28 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:37:30 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	find_smallest(t_int_arr *a, t_value *value)
{
	size_t	i;

	value->min = MAXINT;
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] < value->min)
		{
			value->min = a->arr[i];
			value->index = i;
		}
		i++;
	}
}

static void	select_smallest(t_int_arr *a, t_int_arr *b,
		t_instructions *instructions)
{
	t_value	value;
	size_t	i;

	find_smallest(a, &value);
	i = 0;
	if (a->size - value.index < value.index)
	{
		while (i < a->size - value.index)
		{			
			stack_reverse_rotate(a);
			instruction_pushback(instructions, "rra");
			i++;
		}
	}
	else
	{
		while (i < value.index)
		{
			stack_rotate(a);
			instruction_pushback(instructions, "ra");
			i++;
		}
	}
	stack_push(b, stack_pop(a));
	instruction_pushback(instructions, "pb");
}

/*
*	Finds the smallest number in the stack a, 
*	rotates the stack fastest way possible until the smallest is first.
*	Pushes the smallest to stack b.
*	Repeats the steps above until stack a is empty.
*	Pushes stack b to stack a.
*/
t_instructions	*select_sort(t_int_arr a, t_int_arr b,
		t_instructions *instructions)
{
	while (a.size > 0)
		select_smallest(&a, &b, instructions);
	while (b.size > 0)
	{
		stack_push(&a, stack_pop(&b));
		instruction_pushback(instructions, "pa");
	}
	remove_extra(instructions);
	return (instructions);
}
