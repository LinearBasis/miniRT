/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:27:51 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:28:19 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_to_scene_plane(t_scene *scene, char *str)
{
	t_point		center;
	t_vector	normal;
	t_color		color;
	int			index;

	index = 3;
	skip_spaces(str, &index);
	if (!read_vector(str, &index, &center))
		return (0);
	if (!read_vector(str, &index, &normal))
		return (0);
	if (!read_color(str, &index, &color))
		return (0);
	if (!is_comment_or_end(str, &index))
		return (0);
	normal = vec_normalize(normal);
	if (!is_good_dir(&normal) || !is_good_color(&color))
		return (0);
	return (scene_add_figure(scene, figure_create(PLANE, &color,
				plane_create(&center, &normal))));
}
