/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:50:18 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:50:19 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	output_instructions(t_instructions *instr)
{
	size_t	i;

	i = 0;
	while (i < instr->size)
	{
		ft_putendl(instr->instr[i]);
		i++;
	}
}
