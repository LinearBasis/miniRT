/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:49:57 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 19:53:04 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_square	*square_create(t_point *center, t_vector *normal, double size)
{
	t_square	*ans;

	ans = malloc(sizeof(*ans));
	if (!ans)
		return (NULL);
	ans->center = *center;
	ans->normal = *normal;
	ans->size = size;
	return (ans);
}

t_vector	get_normal_from_square(t_figure *fig, t_point *point)
{
	(void)point;
	return (((t_square *)fig->obj)->normal);
}

void	get_basis_of_square(t_vector *normal, t_vector *vec1,
	t_vector *vec2)
{
	int			flag;
	t_vector	r;

	flag = 0;
	r = vec_create(1, 0, 0);
	if (fabs(vec_scalar_prod(r, *normal)) >= 1 - 1E-4)
	{
		flag = 1;
		r = vec_create(0, 1, 0);
	}
	if (!flag)
	{
		*vec1 = vec_normalize(vec_cross_prod(*normal, r));
		*vec2 = vec_cross_prod(*normal, *vec1);
	}
	else
	{
		*vec2 = vec_normalize(vec_cross_prod(*normal, r));
		*vec1 = vec_cross_prod(*normal, *vec2);
	}
}
