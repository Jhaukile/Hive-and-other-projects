/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:39:14 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:39:15 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_instructions	*simple_sort(t_int_arr a, t_instructions *instructions)
{
	if (a.arr[0] == a.arr[1] + 1 || a.arr[0] + 2 == a.arr[1])
	{
		stack_swap(&a.arr[0], &a.arr[1], a.size);
		instruction_pushback(instructions, "sa");
	}
	if (a.arr[2] + 2 == a.arr[1])
	{
		stack_reverse_rotate(&a);
		instruction_pushback(instructions, "rra");
	}
	else if (a.arr[0] == a.arr[1] + 2)
	{
		stack_rotate(&a);
		instruction_pushback(instructions, "ra");
	}
	return (instructions);
}
