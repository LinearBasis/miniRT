/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:03:22 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:19:33 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	solve_square(double k[3], double *d1, double *d2)
{
	double	discriminant;
	double	a;

	a = k[2];
	*d1 = INFINITY;
	*d2 = INFINITY;
	if (k[1] * k[1] < 4 * k[2] * k[0])
		return (0);
	discriminant = sqrt(k[1] * k[1] - 4 * k[2] * k[0]);
	*d1 = (-k[1] + discriminant) / (2 * a);
	*d2 = (-k[1] - discriminant) / (2 * a);
	return (2);
}

static double	asd(t_vector *dir, t_cylinder *cyl,
				t_point *origin)
{
	t_vector	oc;
	double		t[3];
	double		x1;
	double		x2;

	oc = vec_dif(cyl->center, *origin);
	t[2] = pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2);
	t[1] = -2 * (dir->x * oc.x + dir->y * oc.y + dir->z * oc.z);
	t[0] = pow(oc.x, 2) + pow(oc.y, 2) + pow(oc.z, 2);
	x1 = vec_scalar_prod(*dir, cyl->dir);
	x2 = vec_scalar_prod(oc, cyl->dir);
	t[2] -= pow(x1, 2);
	t[1] -= -2 * x1 * x2;
	t[0] -= pow(x2, 2);
	t[0] += -pow(cyl->diameter / 2, 2);
	solve_square(t, &x1, &x2);
	if (x2 > 0 && x2 < INFINITY && fabs(vec_scalar_prod(cyl->dir,
				vec_dif(vec_sum(*origin, vec_mult(x2, *dir)), cyl->center)))
		< cyl->height / 2)
		return (x2);
	if (x1 > 0 && x1 < INFINITY && fabs(vec_scalar_prod(cyl->dir,
				vec_dif(vec_sum(*origin, vec_mult(x1, *dir)), cyl->center)))
		< cyl->height / 2)
		return (x1);
	return (INFINITY);
}

double	cylinder_intersect(t_vector *dir, t_cylinder *cylinder,
				t_point *origin)
{
	double	t;

	t = asd(dir, cylinder, origin);
	return (t);
}
