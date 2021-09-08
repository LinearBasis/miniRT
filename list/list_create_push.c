/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:42:51 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:26:18 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_list	*list_create(void *data)
{
	t_list	*ans;

	ans = (t_list *)malloc(sizeof(t_list));
	ans->next = ans;
	ans->prev = ans;
	ans->data = data;
	return (ans);
}

void	list_push_back(t_list **lst, t_list *tmp)
{
	t_list	*p;
	t_list	*begin;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = tmp;
		return ;
	}
	begin = *lst;
	*lst = (*lst)->prev;
	p = (*lst)->next;
	(*lst)->next = tmp;
	tmp->next = p;
	tmp->prev = *lst;
	p->prev = tmp;
	*lst = begin;
}
