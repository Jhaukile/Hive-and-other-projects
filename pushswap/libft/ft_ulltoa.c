/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:48:36 by jlehtine          #+#    #+#             */
/*   Updated: 2022/01/07 05:24:02 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	recursive_count(unsigned long long n, size_t count, int base)
{
	if (n == 0)
		return (count);
	return (recursive_count(n / base, count + 1, base));
}

static size_t	ft_cntdig_base(unsigned long long n, int base)
{
	if (n == 0)
		return (1);
	return (recursive_count(n, 0, base));
}

char	*ft_ulltoa(unsigned long long n, int base)
{
	char	*str;
	size_t	size;
	int		remain;

	size = ft_cntdig_base(n, base);
	str = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (size--)
	{
		remain = n % base;
		if (remain > 9)
			str[size] = (char)(remain - 10 + 'A');
		else
			str[size] = (char)(remain + '0');
		n /= base;
	}
	return (str);
}
