/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:00:02 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/25 15:00:22 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *str, int c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[0] != c)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}
