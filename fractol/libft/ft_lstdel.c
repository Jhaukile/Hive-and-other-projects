/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:28:59 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/25 16:37:06 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*successor;

	while (*alst)
	{
		successor = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = successor;
	}
	*alst = NULL;
}
