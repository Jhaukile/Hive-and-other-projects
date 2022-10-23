/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:07:21 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/26 02:05:21 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	count;
	char	*str;
	int		negative;
	int		result;

	negative = n < 0;
	count = ft_cntdig(n) + negative;
	str = (char *)ft_memalloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (negative)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	str[count] = '\0';
	while (n != 0)
	{
		count--;
		result = n % 10;
		result = ft_abs(result);
		str[count] = (char)(result + '0');
		n /= 10;
	}
	return (str);
}
