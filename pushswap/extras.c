/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:19:27 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:19:28 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	is_opposite(char *a, char *b)
{
	if (ft_strcmp(a, "ra") == 0)
		return (ft_strcmp(b, "rra") == 0);
	else if (ft_strcmp(a, "rb") == 0)
		return (ft_strcmp(b, "rrb") == 0);
	else if (ft_strcmp(a, "pb") == 0)
		return (ft_strcmp(b, "pa") == 0);
	else if (ft_strcmp(a, "pa") == 0)
		return (ft_strcmp(b, "pb") == 0);
	else if (ft_strcmp(a, "sa") == 0)
		return (ft_strcmp(b, "sa") == 0);
	else if (ft_strcmp(a, "sb") == 0)
		return (ft_strcmp(b, "sb") == 0);
	return (0);
}

static int	can_swap(char **instr, int index, int is_a)
{
	if (is_a && ft_strcmp(instr[index], "ra") == 0
		&& ft_strcmp(instr[index + 1], "pb") == 0
		&& ft_strcmp(instr[index + 2], "rra") == 0
		&& ft_strcmp(instr[index + 3], "pa") == 0)
		return (1);
	if (!is_a && ft_strcmp(instr[index], "rb") == 0
		&& ft_strcmp(instr[index + 1], "pa") == 0
		&& ft_strcmp(instr[index + 2], "rrb") == 0
		&& ft_strcmp(instr[index + 3], "pb") == 0)
		return (1);
	return (0);
}

static int	instruction_swap(t_instructions *instructions, int i, char *instr)
{
	remove_instruction(instructions, i);
	remove_instruction(instructions, i);
	remove_instruction(instructions, i);
	remove_instruction(instructions, i);
	instruction_insert(instructions, instr, i);
	return (1);
}

static int	removed_extra(t_instructions *instructions)
{
	size_t	i;

	if (instructions->size <= 0)
		return (0);
	i = 0;
	while (i < instructions->size - 1)
	{
		if (is_opposite(instructions->instr[i], instructions->instr[i + 1]))
		{
			remove_instruction(instructions, i);
			remove_instruction(instructions, i);
			return (1);
		}
		if (can_swap(instructions->instr, i, 1))
			return (instruction_swap(instructions, i, "sa"));
		if (can_swap(instructions->instr, i, 0))
			return (instruction_swap(instructions, i, "sb"));
		i++;
	}
	return (0);
}

void	remove_extra(t_instructions *instructions)
{
	while (1)
	{
		if (!removed_extra(instructions))
			break ;
	}
}
