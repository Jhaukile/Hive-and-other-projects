/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:19:47 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/15 13:14:24 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = (void *)malloc(size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
