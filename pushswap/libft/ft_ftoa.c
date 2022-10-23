/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:57:46 by jlehtine          #+#    #+#             */
/*   Updated: 2022/01/07 05:37:43 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_two_ptr(void *ptr1, void *ptr2)
{
	ft_memdel(ptr1);
	ft_memdel(ptr2);
	return (NULL);
}

static char	*add_zeros(long fpoint, size_t precision)
{
	char	*ptr;

	if (fpoint == 0)
	{
		ptr = ft_strnew(precision);
		ptr = ft_memset(ptr, '0', precision);
		return (ptr);
	}
	return (ft_itoa(fpoint));
}

static char	*convert_to_str(long complete, long fpoint, size_t precision)
{
	char	*str1;
	char	*str2;
	char	*result;
	char	*ptr;

	str1 = ft_lltoa(complete, 10);
	if (precision == 0)
		return (str1);
	str2 = add_zeros(fpoint, precision);
	if (!str1 || !str2)
		return (free_two_ptr(&str1, &str2));
	ptr = ft_strjoin(str1, ".");
	ft_memdel((void **)&str1);
	if (!ptr)
	{
		ft_memdel((void **)&str2);
		return (NULL);
	}
	result = ft_strjoin(ptr, str2);
	free_two_ptr(&str2, &ptr);
	return (result);
}

static unsigned long	ft_pow64(int base, int power)
{
	unsigned long	res;

	res = 1;
	while (power--)
		res *= base;
	return (res);
}

char	*ft_ftoa(long double n, size_t precision)
{
	long	complete;
	double	fpoint;
	long	round;

	complete = (long)n;
	fpoint = n - (double)complete;
	fpoint *= (double)(ft_pow64(10, precision));
	round = fpoint * 10;
	fpoint = (double)ft_abs((long)fpoint);
	round = ft_abs(round);
	round = (long)(round - (long)(fpoint)*10);
	if (round >= 5)
		fpoint++;
	return (convert_to_str(complete, (long)fpoint, precision));
}
