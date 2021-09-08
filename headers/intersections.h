/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:34:39 by dnicki            #+#    #+#             */
/*   Updated: 2021/03/24 19:14:14 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "vector.h"
# include "figures.h"

double		any_intersect(t_vector *dir, t_figure *fig,
				t_point *origin);
double		sphere_intersect(t_vector *dir, t_sphere *sphere,
				t_point *origin);
double		plane_intersect(t_vector *dir, t_plane *plane,
				t_point *origin);
double		square_intersect(t_vector *dir, t_square *square,
				t_point *origin);
double		triangle_intersect(t_vector *dir, t_triangle *triangle,
				t_point *origin);
double		cylinder_intersect(t_vector *dir, t_cylinder *cylinder,
				t_point *origin);
#endif
