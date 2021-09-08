/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:31:16 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:28:31 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_to_scene_square(t_scene *scene, char *str)
{
	t_point		center;
	t_vector	normal;
	double		size;
	t_color		color;
	int			index;

	if (!str_find_in_begin(str, "sq"))
		return (0);
	index = 3;
	skip_spaces(str, &index);
	if (!read_vector(str, &index, &center))
		return (0);
	if (!read_vector(str, &index, &normal))
		return (0);
	if (!read_one_double_and_skip_ends(str, &index, &size, " "))
		return (0);
	if (!read_color(str, &index, &color))
		return (0);
	if (vec_abs(normal) < 1E-9)
		return (0);
	normal = vec_normalize(normal);
	if (!is_good_color(&color))
		return (0);
	return (scene_add_figure(scene, figure_create(SQUARE, &color,
				square_create(&center, &normal, size))));
}
