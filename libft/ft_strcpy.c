/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:55:31 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/12 12:25:51 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *sourc)
{
	int	i;

	i = 0;
	while (sourc[i] != '\0')
	{
		dest[i] = sourc[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
