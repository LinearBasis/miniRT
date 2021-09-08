/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 22:47:18 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:35:28 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_to_scene_light(t_scene *scene, char *str)
{
	t_color		color;
	double		br;
	int			index;
	t_point		center;

	if (!str_find_in_begin(str, "l"))
		return (0);
	index = 2;
	skip_spaces(str, &index);
	if (!read_vector(str, &index, &center))
		return (0);
	if (!read_one_double_and_skip_ends(str, &index, &br, " "))
		return (0);
	if (!read_color(str, &index, &color))
		return (0);
	if (!is_good_brightness(br) || !is_good_color(&color))
		return (0);
	return (scene_add_light(scene, light_create(&center, &color, br)));
}
