/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:34:38 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 14:46:24 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_sphere	*sphere_create(t_point *center, double r)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!(sphere))
		return (NULL);
	sphere->center = *center;
	sphere->r = r;
	return (sphere);
}

t_vector	get_normal_from_sphere(t_figure *fig, t_point *point)
{
	t_sphere	sphere;

	sphere = *(t_sphere *)fig->obj;
	return (vec_normalize(vec_dif(*point, sphere.center)));
}
