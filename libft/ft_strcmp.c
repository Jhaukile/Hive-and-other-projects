/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:55:08 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/12 14:46:46 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	while (*ptr1 && (*ptr1 == *ptr2))
	{
		ptr1 += 1;
		ptr2 += 1;
	}
	return (*ptr1 - *ptr2);
}
