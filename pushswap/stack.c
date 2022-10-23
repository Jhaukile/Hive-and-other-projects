/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:39:34 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:39:35 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	stack_swap(int *a, int *b, size_t size)
{
	if (size < 2)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	stack_push(t_int_arr *stack, int *item)
{
	int	i;

	if (!item)
		return ;
	i = stack->size;
	while (i)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = *item;
	stack->size++;
	ft_memdel((void **)&item);
}

int	*stack_pop(t_int_arr *stack)
{
	size_t	i;
	int		*item;

	i = 0;
	if (stack->size < 1)
		return (NULL);
	item = (int *)ft_memalloc(sizeof(int));
	if (!item)
		return (NULL);
	*item = stack->arr[0];
	while (i + 1 < stack->size)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->size--;
	return (item);
}

void	stack_reverse_rotate(t_int_arr *stack)
{
	size_t	i;
	int		last;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	last = stack->arr[stack->size - 1];
	while (i)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = last;
}

void	stack_rotate(t_int_arr *stack)
{
	size_t	i;
	int		first;

	if (stack->size < 2)
		return ;
	i = 0;
	first = stack->arr[0];
	while (i + 1 < stack->size)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->size - 1] = first;
}
