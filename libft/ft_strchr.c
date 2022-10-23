/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:14:52 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/15 12:50:49 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c != '\0')
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return ((char *)&s[i]);
			else
				i++;
		}
	}
	else if (c == '\0')
	{
		while (s[i] != c)
			i++;
		return ((char *)&s[i]);
	}
	return (NULL);
}
