/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntdig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:57:09 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/26 03:37:45 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	recursive_count(int n, size_t count)
{
	if (n == 0)
		return (count);
	return (recursive_count(n / 10, count + 1));
}

size_t	ft_cntdig(int n)
{
	if (n == 0)
		return (1);
	return (recursive_count(n, 0));
}
