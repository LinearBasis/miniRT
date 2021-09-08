/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:34:09 by dnicki            #+#    #+#             */
/*   Updated: 2021/08/27 17:56:12 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	void			*data;
}				t_list;

t_list			*list_create(void *data);
void			list_push_back(t_list **list, t_list *add);
void			list_iter(t_list *lst, void (*f)(void*));
void			list_clear(t_list **lst, void (*del)(void*));
t_list			*list_map(t_list *lst, void *(*f)(void*), void (*del)(void*));
#endif
