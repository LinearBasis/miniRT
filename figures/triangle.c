/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:43:56 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 18:04:06 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_triangle	*triangle_create(t_point *p1, t_point *p2, t_point *p3)
{
	t_triangle	*ans;

	ans = malloc(sizeof(*ans));
	if (!ans)
		return (ans);
	ans->p1 = *p1;
	ans->p2 = *p2;
	ans->p3 = *p3;
	ans->normal = vec_normalize(vec_cross_prod(vec_dif(*p2, *p1),
				vec_dif(*p3, *p1)));
	return (ans);
}

t_vector	get_normal_from_triangle(t_figure *fig, t_point *point)
{
	(void)point;
	return (((t_triangle *)fig->obj)->normal);
}
