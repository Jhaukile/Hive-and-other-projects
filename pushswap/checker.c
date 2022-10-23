/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:16:15 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:16:25 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	validate_results(t_int_arr *a, t_int_arr *b)
{
	size_t	i;

	i = 0;
	if (a->size != a->space || b->size > 0)
	{
		ft_putendl("KO");
		return ;
	}
	while (i + 1 < a->size)
	{
		if (a->arr[i + 1] < a->arr[i])
		{
			ft_putendl("KO");
			return ;
		}
		i++;
	}
	ft_putendl("OK");
}

static void	at_exit(int print_error)
{
	if (print_error)
		ft_putendl_fd("Error", 2);
	exit(1);
}

static void	free_all(t_int_arr *stack_a, t_int_arr *stack_b,
				t_instructions *instr, t_arguments *arg)
{
	free_2d_arr(instr->instr, instr->space);
	free_2d_arr(arg->argv, arg->argc);
	ft_memdel((void **)&stack_a->arr);
	ft_memdel((void **)&stack_b->arr);
}

int	main(int argc, char **argv)
{
	t_int_arr		stack_a;
	t_int_arr		stack_b;
	t_instructions	instructions;
	int				ret;
	t_arguments		arg;

	if (argc < 2)
		return (0);
	arg = fix_arguments(argc - 1, &argv[1]);
	if (!validate_arguments(arg.argc, arg.argv))
		at_exit(1);
	stack_a = make_int_array(arg.argc, arg.argv);
	if (stack_a.size == 0)
		at_exit(stack_a.size == 0);
	ret = read_instructions(&instructions);
	if (ret != 1)
		at_exit(ret == -1);
	stack_b.size = 0;
	stack_b.arr = (int *)ft_memalloc(sizeof(int) * stack_a.size);
	if (!stack_b.arr)
		return (-1);
	execute_instructions(instructions.instr, &stack_a, &stack_b);
	validate_results(&stack_a, &stack_b);
	free_all(&stack_a, &stack_b, &instructions, &arg);
	return (0);
}
