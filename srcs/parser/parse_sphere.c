/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:09:51 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:28:23 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_to_scene_sphere(t_scene *scene, char *str)
{
	t_vector	center;
	t_color		color;
	double		diameter;
	int			index;

	if (!str_find_in_begin(str, "sp"))
		return (0);
	index = 3;
	skip_spaces(str, &index);
	if (!read_vector(str, &index, &center))
		return (0);
	if (!read_one_double_and_skip_ends(str, &index, &diameter, " "))
		return (0);
	if (!read_color(str, &index, &color))
		return (0);
	if (!is_good_color(&color) || !is_good_radius(diameter / 2))
		return (0);
	return (scene_add_figure(scene, figure_create(SPHERE, &color,
				sphere_create(&center, diameter / 2))));
}
