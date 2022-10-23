/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:42:08 by jlehtine          #+#    #+#             */
/*   Updated: 2022/09/22 14:42:09 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Returns how many words are in a string
*/
int	ft_winstr(const char *str)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			words++;
			while (!ft_isspace(*str) && *str)
				str++;
		}
		while (ft_isspace(*str))
			str++;
	}
	return (words);
}
