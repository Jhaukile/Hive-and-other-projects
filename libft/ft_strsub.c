/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:48:19 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/15 13:38:49 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (ft_strlen(s) == 0)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	if (len == 0)
	{
		new[i] = '\0';
		return (new);
	}
	while (i < len && s[i + start] != '\0')
	{
		new[i] = s[i + start];
		i++;
	}
	while (i < len)
		new[i++] = '\0';
	new[i] = '\0';
	return (new);
}
