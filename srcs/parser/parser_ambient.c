/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:07:02 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:34:11 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_to_scene_ambient(t_scene *scene, char *str)
{
	int		index;

	if (!str_find_in_begin(str, "A")
		|| !scene || scene->ambient.brightness != -1)
		return (0);
	index = 2;
	skip_spaces(str, &index);
	if (!read_one_double_and_skip_ends(str, &index,
			&(scene->ambient.brightness), " "))
		return (0);
	if (!read_color(str, &index, &(scene->ambient.color)))
		return (0);
	if (!is_comment_or_end(str, &index))
		return (0);
	if (!is_good_ambient(&(scene->ambient)))
		return (0);
	return (1);
}
