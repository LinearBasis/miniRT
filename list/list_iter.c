/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:30:54 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:27:52 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

void	list_iter(t_list *lst, void (*f)(void*))
{
	t_list	*begin;

	begin = lst;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
		if (begin == lst)
			break ;
	}
}

void	list_clear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*begin;

	if (lst)
		begin = *lst;
	else
		return ;
	if (!*lst)
		return ;
	while (lst && *lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (del)
			del(tmp->data);
		free(tmp);
		if (*lst == begin)
			break ;
	}
	*lst = NULL;
}

t_list	*list_map(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*ans;
	t_list	*tmp;

	ans = NULL;
	while (lst)
	{
		tmp = list_create(f(lst->data));
		if (!(tmp))
		{
			list_clear(&lst, del);
			return (NULL);
		}
		list_push_back(&ans, tmp);
		lst = lst->next;
	}
	return (ans);
}
