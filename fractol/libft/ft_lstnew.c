/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:15:25 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/25 16:36:53 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cont;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	cont = (void *)content;
	if (cont == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		cont = (void *)malloc(content_size);
		ft_memcpy(cont, content, content_size);
		new->content = cont;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
