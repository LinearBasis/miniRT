/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:46:57 by dnicki            #+#    #+#             */
/*   Updated: 2021/08/27 15:32:13 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}					t_vector;

typedef t_vector	t_point;

t_vector			vec_create(double x, double y, double z);
t_vector			vec_cross_prod(t_vector vec1, t_vector vec2);
double				vec_scalar_prod(t_vector vec1, t_vector vec2);
double				vec_abs(t_vector vec);

t_vector			vec_dif(t_vector vec1, t_vector vec2);
t_vector			vec_sum(t_vector vec1, t_vector vec2);
t_vector			vec_mult(double k, t_vector vec);
t_vector			vec_normalize(t_vector vec);
double				vec_cos(t_vector vec1, t_vector vec2);
void				print_vec(t_vector vec);

#endif
