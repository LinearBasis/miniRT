/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:25:11 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:20:50 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

static double	get_k_of_intersect_with_plane(t_vector *dir, t_square *square,
	t_point *origin)
{
	t_plane		plane;
	double		k;

	plane.center = square->center;
	plane.normal = square->normal;
	k = plane_intersect(dir, &plane, origin);
	return (k);
}

double	square_intersect(t_vector *dir, t_square *square,
	t_point *origin)
{
	double		k;
	t_vector	vec1;
	t_vector	vec2;
	t_point		dot;

	k = get_k_of_intersect_with_plane(dir, square, origin);
	if (k == INFINITY)
		return (k);
	dot = vec_sum(vec_mult(k, *dir), *origin);
	dot = vec_dif(dot, square->center);
	get_basis_of_square(&(square->normal), &vec1, &vec2);
	if (fabs(vec_scalar_prod(dot, vec1)) <= square->size / 2
		&& fabs(vec_scalar_prod(dot, vec2)) <= square->size / 2)
		return (k);
	return (INFINITY);
}
