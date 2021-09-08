/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:02:31 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:28:08 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_to_scene_cylinder(t_scene *scene, char *str)
{
	t_vector	center_dir[2];
	double		dh[2];
	int			index;
	t_color		color;

	if (!str_find_in_begin(str, "cy"))
		return (-1);
	index = 2;
	skip_spaces(str, &index);
	if (!read_vector(str, &index, &(center_dir[0])))
		return (0);
	if (!read_vector(str, &index, &(center_dir[1])))
		return (0);
	if (!read_one_double_and_skip_ends(str, &index, &(dh[0]), " "))
		return (0);
	if (!read_one_double_and_skip_ends(str, &index, &(dh[1]), " "))
		return (0);
	if (!read_color(str, &index, &color))
		return (0);
	if (vec_abs(center_dir[1]) < 1E-9 || !is_good_color(&color))
		return (0);
	center_dir[1] = vec_normalize(center_dir[1]);
	return (scene_add_figure(scene, figure_create(CYLINDER, &color,
				cylinder_create(center_dir[1], dh, center_dir[0]))));
}
