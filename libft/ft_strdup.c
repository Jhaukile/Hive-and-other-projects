/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:25:09 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/12 12:26:15 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*str;

	index = 0;
	while (s1[index] != '\0')
		index++;
	str = (char *)malloc(sizeof(char) * index + 1);
	if (str == 0)
		return (0);
	index = 0;
	while (s1[index] != '\0')
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
