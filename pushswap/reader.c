/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:32:38 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:32:39 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static char	**fill_options(void)
{
	char	**options;

	options = (char **)ft_memalloc(sizeof(char *) * 11);
	if (!options)
		return (NULL);
	options[0] = ft_strdup("sa\0");
	options[1] = ft_strdup("sb\0");
	options[2] = ft_strdup("ss\0");
	options[3] = ft_strdup("pa\0");
	options[4] = ft_strdup("pb\0");
	options[5] = ft_strdup("ra\0");
	options[6] = ft_strdup("rb\0");
	options[7] = ft_strdup("rr\0");
	options[8] = ft_strdup("rra\0");
	options[9] = ft_strdup("rrb\0");
	options[10] = ft_strdup("rrr\0");
	return (options);
}

static int	validate_instruction(char **options, char *instruction)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(options[i], instruction) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	read_instructions(t_instructions *instr)
{
	char	*line;
	char	**options;
	int		ret;

	options = fill_options();
	if (!init_instructions(instr))
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		ret = validate_instruction(options, line);
		if (ret == -1)
			return (-1);
		instr->instr[instr->size] = ft_strdup(options[ret]);
		instr->size++;
		ft_memdel((void **)&line);
		if (instr->size >= instr->space)
		{
			instr->instr = realloc_instructions(instr, instr->space * 2);
			if (!instr->instr)
				return (0);
		}
	}
	ft_memdel((void **)&line);
	free_2d_arr(options, 11);
	return (1);
}
