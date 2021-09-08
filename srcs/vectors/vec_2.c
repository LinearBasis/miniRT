/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:08:23 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 17:57:15 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_vector	vec_sum(t_vector vec1, t_vector vec2)
{
	return (vec_create(vec1.x + vec2.x, vec1.y + vec2.y,
			vec1.z + vec2.z));
}

t_vector	vec_dif(t_vector vec1, t_vector vec2)
{
	return (vec_create(vec1.x - vec2.x, vec1.y - vec2.y,
			vec1.z - vec2.z));
}

t_vector	vec_mult(double k, t_vector vec)
{
	return (vec_create(vec.x * k, vec.y * k, vec.z * k));
}

t_vector	vec_normalize(t_vector vec)
{
	return (vec_mult(1. / vec_abs(vec), vec));
}

double	vec_cos(t_vector vec1, t_vector vec2)
{
	return (vec_scalar_prod(vec1, vec2) / (vec_abs(vec1) * vec_abs(vec2)));
}
