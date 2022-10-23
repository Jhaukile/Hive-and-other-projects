/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:18:39 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/15 12:47:55 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_israndom(int c)
{
	return (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f' \
			|| c == ' ');
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	if (!str[i])
		return (0);
	while (ft_israndom(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * neg);
}
