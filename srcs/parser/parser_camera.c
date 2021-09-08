/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:00:32 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 17:45:52 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_to_scene_camera(t_scene *scene, char *str)
{
	t_vector	dir;
	t_point		center;
	double		fov;
	int			index;

	if (!str_find_in_begin(str, "c"))
		return (0);
	index = 1;
	skip_spaces(str, &index);
	if (!read_vector(str, &index, &center))
		return (0);
	if (!read_vector(str, &index, &dir))
		return (0);
	if (!read_one_double_and_skip_ends(str, &index, &fov, " "))
		return (0);
	if (!is_comment_or_end(str, &index))
		return (0);
	dir = vec_normalize(dir);
	if (vec_abs(dir) == 0)
		return (0);
	if (!is_good_fov(fov) || !is_good_dir(&dir))
		return (0);
	return (scene_add_camera(scene, camera_create(&center, &dir, fov)));
}
