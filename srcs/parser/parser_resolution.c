/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:59:21 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 19:42:25 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_to_scene_resolution(t_scene *scene, char *str)
{
	int	num;
	int	index;

	if (!str_find_in_begin(str, "R")
		|| !scene || scene->height != -1 || scene->width != -1)
		return (0);
	index = 2;
	skip_spaces(str, &index);
	if (!read_one_int_and_skip_ends(str, &index, &num, " "))
		return (0);
	scene->width = min(num, 2880);
	if (!read_one_int_and_skip_ends(str, &index, &num, " "))
		return (0);
	scene->height = min(num, 1620);
	return (1);
}
