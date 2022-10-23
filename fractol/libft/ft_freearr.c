/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:52:03 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/25 16:37:20 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freearr(char **dest)
{
	size_t	s;

	s = 0;
	while (dest[s])
	{
		free(dest[s]);
		s++;
	}
	free(dest);
	dest = NULL;
	return (dest);
}
