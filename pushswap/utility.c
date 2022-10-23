/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:40:10 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:40:11 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	is_over_maxint(const char *num)
{
	char	*maxint;
	size_t	num_len;

	if (*num == '-')
		return (0);
	maxint = "2147483647";
	num_len = ft_strlen(num);
	if (num_len == 10)
	{
		while (*num)
		{
			if (*num != *maxint)
				return (*num > *maxint);
			num++;
			maxint++;
		}
		return (0);
	}
	return (num_len > 10);
}

static int	is_over_minint(const char *num)
{
	char	*minint;
	size_t	num_len;

	if (*num != '-')
		return (0);
	num++;
	minint = "2147483648";
	num_len = ft_strlen(num);
	if (num_len == 10)
	{
		while (*num)
		{
			if (*num != *minint)
				return (*num > *minint);
			num++;
			minint++;
		}
		return (0);
	}
	return (num_len > 10);
}

int	validate_arguments(int ac, char **av)
{
	while (ac--)
	{
		if (is_over_maxint(*av) || is_over_minint(*av))
			return (0);
		av++;
	}
	return (1);
}

char	**join_arrays(int ac1, int ac2, char **av1, char **av2)
{
	char	**new_arr;
	int		i;
	int		j;

	new_arr = (char **)ft_memalloc(sizeof(char *) * (ac1 + ac2));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < ac1)
	{
		new_arr[i] = ft_strdup(av1[i]);
		i++;
	}
	j = 0;
	while (j < ac2)
	{
		new_arr[i] = ft_strdup(av2[j]);
		i++;
		j++;
	}
	free_2d_arr(av2, ac2);
	return (new_arr);
}

t_int_arr	simple_array(t_int_arr stack)
{
	size_t		i;
	int			val;
	t_int_arr	new_stack;

	new_stack.arr = (int *)ft_memalloc(stack.space * sizeof(int));
	if (!new_stack.arr)
		return (stack);
	new_stack.space = stack.space;
	new_stack.size = 0;
	while (new_stack.size != stack.size)
	{
		val = stack.arr[new_stack.size];
		i = 0;
		new_stack.arr[new_stack.size] = 0;
		while (i < stack.size)
		{
			if (val > stack.arr[i])
				new_stack.arr[new_stack.size]++;
			i++;
		}
		new_stack.size++;
	}
	ft_memdel((void **)&stack.arr);
	return (new_stack);
}
