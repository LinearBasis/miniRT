/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:11:53 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 16:52:32 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_cylinder	*cylinder_create(t_vector dir, double dh[2], t_point center)
{
	t_cylinder		*ans;

	ans = malloc(sizeof(t_cylinder));
	if (!(ans))
		return (ans);
	ans->dir = dir;
	ans->diameter = dh[0];
	ans->height = dh[1];
	ans->center = center;
	return (ans);
}

t_vector	get_normal_from_cylinder(t_figure *fig, t_point *point)
{
	t_cylinder	*cyl;
	t_vector	n;
	t_vector	v;
	double		k;
	t_point		c0;

	cyl = fig->obj;
	v = vec_dif(*point, cyl->center);
	k = vec_scalar_prod(v, cyl->dir);
	c0 = vec_sum(cyl->center, vec_mult(k, cyl->dir));
	n = vec_normalize(vec_dif(*point, c0));
	return (n);
}
