/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_intersect_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:55:52 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:15:18 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

double	any_intersect(t_vector *dir, t_figure *fig, t_point *origin)
{
	if (!dir || !fig || !origin)
		return (INFINITY);
	if (fig->fig_id == SPHERE)
		return (sphere_intersect(dir, (t_sphere *)fig->obj, origin));
	else if (fig->fig_id == PLANE)
		return (plane_intersect(dir, ((t_plane *)fig->obj), origin));
	else if (fig->fig_id == SQUARE)
		return (square_intersect(dir, (t_square *)fig->obj, origin));
	else if (fig->fig_id == TRIANGLE)
		return (triangle_intersect(dir, (t_triangle *)fig->obj, origin));
	else if (fig->fig_id == CYLINDER)
		return (cylinder_intersect(dir, (t_cylinder *)fig->obj, origin));
	return (INFINITY);
}
