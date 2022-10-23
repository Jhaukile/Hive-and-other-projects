/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:32:03 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/25 11:47:42 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(char const *s)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n')
	{
		j--;
	}
	if (i > j)
		return (0);
	return (ft_strlen(s) - (ft_strlen(s) - j + i));
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		length;
	char	*str;

	if (s == NULL)
		return (NULL);
	length = ft_check(s);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (j < length)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
