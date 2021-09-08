/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:50:08 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:21:22 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

static double	get_k_of_intersect_with_plane(t_vector *dir,
		t_triangle *triangle, t_point *origin)
{
	t_plane		plane;
	double		k;

	plane.center = triangle->p1;
	plane.normal = triangle->normal;
	k = plane_intersect(dir, &plane, origin);
	return (k);
}

static int	is_dot_between_vecs(t_point p2, t_point p1, t_point p3,
	t_point dot)
{
	t_vector	vec1;
	t_vector	vec2;
	t_vector	to_dot;
	double		scal;

	vec1 = vec_normalize(vec_dif(p2, p1));
	vec2 = vec_normalize(vec_dif(p3, p1));
	to_dot = vec_normalize(vec_dif(dot, p1));
	scal = vec_scalar_prod(vec1, vec2);
	if (scal <= vec_scalar_prod(vec1, to_dot)
		&& scal <= vec_scalar_prod(vec2, to_dot))
		return (1);
	return (0);
}

double	triangle_intersect(t_vector *dir, t_triangle *triangle,
				t_point *origin)
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		dot;
	double		k;

	k = get_k_of_intersect_with_plane(dir, triangle, origin);
	if (k == INFINITY)
		return (k);
	p1 = triangle->p1;
	p2 = triangle->p2;
	p3 = triangle->p3;
	dot = vec_sum(vec_mult(k, *dir), *origin);
	if (is_dot_between_vecs(p2, p1, p3, dot)
		&& is_dot_between_vecs(p3, p2, p1, dot))
		return (k);
	return (INFINITY);
}
