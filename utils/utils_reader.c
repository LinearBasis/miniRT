/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:47:40 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:43:29 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	read_one_int_and_skip_ends(char *str, int *index, int *num,
		char *ends)
{
	*num = ft_atoi(str + *index);
	if (!skip_int_ends(str, index, ends))
		return (0);
	if (str[*index])
		(*index)++;
	skip_spaces(str, index);
	return (1);
}

int	read_one_double_and_skip_ends(char *str, int *index, double *num,
		char *ends)
{
	*num = ft_atof(str + *index);
	if (!skip_double_ends(str, index, ends))
		return (0);
	if (str[*index])
		(*index)++;
	skip_spaces(str, index);
	return (1);
}

int	is_comment_or_end(char *str, int *i)
{
	skip_spaces(str, i);
	if (str[*i] == '#' || !str[*i])
		return (1);
	return (0);
}

int	read_vector(char *str, int *index, t_vector *vec)
{
	if (!read_one_double_and_skip_ends(str, index, &(vec->x), ","))
		return (0);
	if (!read_one_double_and_skip_ends(str, index, &(vec->y), ","))
		return (0);
	if (!read_one_double_and_skip_ends(str, index, &(vec->z), " "))
		return (0);
	return (1);
}

int	read_color(char *str, int *index, t_color *color)
{
	if (!read_one_int_and_skip_ends(str, index, &(color->r), ","))
		return (0);
	if (!read_one_int_and_skip_ends(str, index, &(color->g), ","))
		return (0);
	if (!read_one_int_and_skip_ends(str, index, &(color->b), " "))
		return (0);
	return (1);
}
