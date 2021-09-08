/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:35:18 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:20:16 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

double	plane_intersect(t_vector *dir, t_plane *plane, t_vector *origin)
{
	t_vector	normal;
	double		denom;
	t_vector	vec;
	double		t;

	normal = plane->normal;
	denom = vec_scalar_prod(normal, *dir);
	if (denom > 0)
	{
		denom *= -1;
		normal = vec_mult(-1, normal);
	}
	vec = vec_dif(plane->center, *origin);
	t = vec_scalar_prod(vec, normal) / denom;
	if (t > 0)
		return (t);
	return (INFINITY);
}
