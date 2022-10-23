/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:32:49 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/15 12:49:56 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n > 0)
	{
		*(ptr++) = *(ptr2++);
		n--;
	}
	return (dst);
}
