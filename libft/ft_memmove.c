/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:13:29 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/15 12:50:03 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr2 < ptr)
	{
		while (++i <= len)
			ptr[len - i] = ptr2[len - i];
	}
	else
	{
		while (len-- > 0)
			*(ptr++) = *(ptr2++);
	}
	return (dst);
}
