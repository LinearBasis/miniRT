/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:35:35 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 14:45:30 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_plane	*plane_create(t_point *center, t_vector *normal)
{
	t_plane	*ans;

	ans = malloc(sizeof(t_plane));
	if (!(ans))
		return (NULL);
	ans->center = *center;
	ans->normal = *normal;
	return (ans);
}

t_vector	get_normal_from_plane(t_figure *fig, t_point *point)
{
	(void)point;
	return (((t_plane *)fig->obj)->normal);
}
