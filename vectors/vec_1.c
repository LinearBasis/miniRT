/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:44:21 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:44:49 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_vector	vec_create(double x, double y, double z)
{
	t_vector	ans;

	ans.x = x;
	ans.y = y;
	ans.z = z;
	return (ans);
}

t_vector	vec_cross_prod(t_vector vec1, t_vector vec2)
{
	double	x;
	double	y;
	double	z;

	x = vec1.y * vec2.z - vec1.z * vec2.y;
	y = vec1.z * vec2.x - vec1.x * vec2.z;
	z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (vec_create(x, y, z));
}

double	vec_scalar_prod(t_vector vec1, t_vector vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

double	vec_abs(t_vector vec)
{
	return (sqrt(vec_scalar_prod(vec, vec)));
}
