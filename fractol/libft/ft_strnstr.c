/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:27:31 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/15 12:53:29 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	needle_len;
	size_t	i;

	ptr = (char *)haystack;
	if (needle[0] == '\0')
		return (ptr);
	i = 0;
	needle_len = (size_t)ft_strlen(needle);
	while (*ptr && len >= needle_len)
	{
		if (*ptr == *needle)
		{
			if (ft_strncmp(needle, ptr, needle_len) == 0)
				return (ptr);
		}
		i++;
		len--;
		ptr++;
	}
	return (NULL);
}
