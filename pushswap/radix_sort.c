/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:30:26 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:30:27 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_msbit(int n)
{
	int	msb;

	msb = 0;
	while (n != 0)
	{
		n >>= 1;
		msb++;
	}
	return (msb);
}

int	most_significant_bit(const int *arr, size_t size)
{
	int	biggest;

	biggest = *arr;
	arr++;
	while (--size)
	{
		if (biggest < *arr)
			biggest = *arr;
		arr++;
	}
	return (ft_msbit(biggest));
}

static void	sort(t_int_arr *a, t_int_arr *b,
		t_instructions *instructions, int checker)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if ((a->arr[0] & checker) == 0)
		{
			stack_push(b, stack_pop(a));
			instruction_pushback(instructions, "pb");
		}
		else
		{
			stack_rotate(a);
			instruction_pushback(instructions, "ra");
		}
		i++;
	}
	while (b->size > 0)
	{
		stack_push(a, stack_pop(b));
		instruction_pushback(instructions, "pa");
	}
}

t_instructions	*radix_sort(t_int_arr a, t_int_arr b,
		t_instructions *instructions)
{
	int	msb;
	int	i;

	msb = most_significant_bit(a.arr, a.size);
	i = 0;
	while (i < msb)
	{
		sort(&a, &b, instructions, 1 << i);
		i++;
	}
	remove_extra(instructions);
	return (instructions);
}