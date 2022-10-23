/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:52:31 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/25 15:00:53 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_s(char const *str, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != '\0' && str[j + i] != c)
		i++;
	return (i);
}

static	char	**ft_strinput(char const *s, char **arr, int c)
{
	int	j;
	int	i;
	int	ind;

	i = 0;
	ind = 0;
	j = ft_countword(s, c);
	while (j--)
	{
		arr[ind] = (char *)malloc(sizeof(char) * (ft_s(s, c) + 1));
		if (!arr[ind])
			return (ft_freearr(&arr[ind]));
		while (*s != '\0' && *s == c)
			s++;
		i = 0;
		while (*s != c && *s != '\0')
			arr[ind][i++] = *s++;
		arr[ind][i] = '\0';
		ind++;
	}
	arr[ind] = NULL;
	return (arr);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		ind;
	int		cint;

	cint = c;
	ind = 0;
	if (s == NULL)
		return (NULL);
	if (s[ind] == '\0')
	{
		arr = (char **)malloc(sizeof(char *) * 1);
		if (!arr)
			return (NULL);
		arr[ind] = NULL;
		return (arr);
	}
	arr = (char **)malloc(sizeof(char *) * (ft_countword(s, cint) + 1));
	if (!arr)
		return (NULL);
	return (ft_strinput(s, arr, cint));
}
