/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:48:19 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/12 14:23:08 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;

	i = 0;
	while (i < n)
	{
		if (((unsigned const char *)s)[i] == (unsigned char)c)
			return ((void *)&((unsigned const char *)s)[i]);
		i += 1;
	}
	return (NULL);
}
