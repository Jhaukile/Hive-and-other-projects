/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:04:12 by jhaukile          #+#    #+#             */
/*   Updated: 2021/11/25 16:38:54 by jhaukile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freelst(t_list **lst)
{
	if ((*lst)->next != NULL)
		ft_freelst(&(*lst)->next);
	free((*lst)->content);
	free((void *) *lst);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*first;

	if (lst && f)
	{
		newlst = f(lst);
		if (!newlst)
			return (NULL);
		first = newlst;
		lst = lst->next;
		while (lst)
		{
			newlst->next = f(lst);
			if (newlst->next == NULL)
			{
				ft_freelst(&first);
				newlst->next = NULL;
				return (NULL);
			}
			newlst = newlst->next;
			lst = lst->next;
		}
		return (first);
	}	
	return (NULL);
}
