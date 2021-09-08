/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:03:07 by dnicki            #+#    #+#             */
/*   Updated: 2021/03/24 18:03:14 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

double	sphere_intersect(t_vector *dir, t_sphere *sphere, t_point *origin)
{
	t_point		point_of_dir;
	t_vector	to_sphere;
	double		len_of_dir;
	double		range;
	double		k;

	to_sphere = vec_dif(sphere->center, *origin);
	len_of_dir = vec_scalar_prod(to_sphere, *dir);
	point_of_dir = vec_sum(vec_mult(len_of_dir, *dir), *origin);
	range = vec_abs(vec_dif(sphere->center, point_of_dir));
	if (range > sphere->r)
		return (INFINITY);
	k = sqrt(sphere->r * sphere->r - range * range);
	if (len_of_dir - k < 0 && len_of_dir + k < 0)
		return (INFINITY);
	else if (len_of_dir - k < 0)
		range = len_of_dir + k;
	else if (len_of_dir + k < 0)
		range = len_of_dir - k;
	else
		range = minlf(len_of_dir - k, len_of_dir + k);
	return (range);
}
