/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 03:32:43 by jlehtine          #+#    #+#             */
/*   Updated: 2022/01/07 05:24:15 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	recursive_count(long long n, size_t count, int base)
{
	if (n == 0)
		return (count);
	return (recursive_count(n / base, count + 1, base));
}

static size_t	ft_cntdig_base(long long n, int base)
{
	if (n == 0)
		return (1);
	return (recursive_count(n, 0, base));
}

char	*ft_lltoa(long long n, int base)
{
	char	*str;
	size_t	size;
	int		remain;

	if (n >= 0)
		return (ft_ulltoa(n, base));
	size = ft_cntdig_base(n, base) + (n < 0);
	str = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (--size)
	{
		remain = ft_abs(n % base);
		if (remain > 9)
			str[size] = (char)(remain - 10 + 'A');
		else
			str[size] = (char)(remain + '0');
		n /= base;
	}
	return (str);
}
