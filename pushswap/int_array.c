/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:26:36 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:26:38 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	is_duplicate(t_int_arr *int_arr, int value)
{
	size_t	i;

	i = 0;
	while (i < int_arr->size)
	{
		if (int_arr->arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	copy_to_int_array(int argc, char **argv, t_int_arr *int_arr)
{
	int	i;
	int	num;

	i = 0;
	while (argc--)
	{
		num = ft_atoi(argv[i]);
		if (num == 0 && argv[i][0] != '0')
		{
			int_arr->size = 0;
			return (0);
		}
		int_arr->arr[i] = (int)num;
		if (is_duplicate(int_arr, int_arr->arr[i]))
		{
			int_arr->size = 0;
			return (0);
		}
		int_arr->size++;
		i++;
	}
	return (1);
}

void	free_2d_arr(char **arr, size_t size)
{
	if (!arr)
		return ;
	while (size--)
	{
		if (arr[size])
			ft_memdel((void **)&arr[size]);
	}
	ft_memdel((void **)&arr);
}

t_arguments	fix_arguments(int argc, char **argv)
{
	t_arguments	arg;
	int			i;
	char		**temp;

	i = 0;
	arg.argc = 0;
	arg.argv = NULL;
	while (i < argc)
	{
		temp = join_arrays(arg.argc,
				ft_winstr(argv[i]), arg.argv, ft_strsplit(argv[i], ' '));
		free_2d_arr(arg.argv, arg.argc);
		arg.argv = temp;
		arg.argc += ft_winstr(argv[i]);
		i++;
	}
	return (arg);
}

t_int_arr	make_int_array(int argc, char **argv)
{
	t_int_arr	int_arr;

	int_arr.size = 0;
	int_arr.space = (size_t)argc;
	int_arr.arr = (int *)ft_memalloc(sizeof(int) * argc);
	if (!int_arr.arr)
		return (int_arr);
	if (!copy_to_int_array(argc, argv, &int_arr))
		ft_memdel((void **)&int_arr.arr);
	return (int_arr);
}
