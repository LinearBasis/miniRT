/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:27:09 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 20:07:49 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_to_scene_triangle(t_scene *scene, char *str)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_color	color;
	int		index;

	index = 2;
	skip_spaces(str, &index);
	if (!read_vector(str, &index, &p1))
		return (0);
	if (!read_vector(str, &index, &p2))
		return (0);
	if (!read_vector(str, &index, &p3))
		return (0);
	if (!read_color(str, &index, &color))
		return (0);
	if (vec_abs(vec_cross_prod(vec_dif(p2, p1), vec_dif(p3, p1))) < 1E-9)
		return (0);
	return (scene_add_figure(scene, figure_create(TRIANGLE, &color,
				triangle_create(&p1, &p2, &p3))));
}
