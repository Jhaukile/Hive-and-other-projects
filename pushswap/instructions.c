/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:23:05 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:23:06 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

char	**realloc_instructions(t_instructions *instructions, size_t new_size)
{
	char	**new_arr;
	size_t	i;

	new_arr = (char **)ft_memalloc(sizeof(char *) * new_size);
	if (!new_arr)
		return (NULL);
	i = instructions->space;
	while (i--)
		new_arr[i] = ft_strdup(instructions->instr[i]);
	free_2d_arr(instructions->instr, instructions->space);
	instructions->space = new_size;
	return (new_arr);
}

void	instruction_insert(t_instructions *instructions,
			char *instr, size_t index)
{
	size_t	i;

	if (instructions->size >= instructions->space)
	{
		instructions->instr = realloc_instructions(instructions,
				instructions->space * 2);
		if (!instructions->instr)
			return ;
	}
	i = instructions->size;
	while (i > index)
	{
		instructions->instr[i] = instructions->instr[i - 1];
		i--;
	}
	instructions->instr[index] = ft_strdup(instr);
	instructions->size++;
}

void	instruction_pushback(t_instructions *instructions, char *instr)
{
	if (instructions->size >= instructions->space)
	{
		instructions->instr = realloc_instructions(instructions,
				instructions->space * 2);
		if (!instructions->instr)
			return ;
	}
	instructions->instr[instructions->size] = ft_strdup(instr);
	instructions->size++;
}

void	remove_instruction(t_instructions *instructions, size_t index)
{
	if (index >= instructions->size || instructions->size <= 0)
		return ;
	ft_memdel((void **)&instructions->instr[index]);
	while (index < instructions->size - 1)
	{
		instructions->instr[index] = instructions->instr[index + 1];
		index++;
	}
	instructions->instr[index] = NULL;
	instructions->size--;
}

t_instructions	*init_instructions(t_instructions *instructions)
{
	instructions->space = 10;
	instructions->size = 0;
	instructions->instr = (char **)ft_memalloc(
			sizeof(char *) * instructions->space);
	if (!instructions->instr)
		return (NULL);
	return (instructions);
}
