/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:04:02 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:12:39 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include "color.h"
# include "vector.h"

# define SPHERE 1
# define PLANE 2
# define SQUARE 3
# define CYLINDER 4
# define TRIANGLE 5

typedef struct s_figure
{
	int			fig_id;
	t_color		color;
	t_vector	(*get_normal_vec)(struct s_figure *fig, t_point *point);
	void		*obj;
}				t_figure;

typedef struct s_sphere
{
	t_point		center;
	double		r;
}				t_sphere;

typedef struct s_plane
{
	t_point		center;
	t_vector	normal;
}				t_plane;

typedef struct s_square
{
	t_point		center;
	t_vector	normal;
	double		size;
}				t_square;

typedef struct s_triangle
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_vector	normal;
}				t_triangle;

typedef struct s_cylinder
{
	t_vector	dir;
	double		diameter;
	double		height;
	t_point		center;
}				t_cylinder;

t_sphere		*sphere_create(t_point *center, double r);
t_vector		get_normal_from_sphere(t_figure *fig, t_point *point);

t_plane			*plane_create(t_point *center, t_vector *normal);
t_vector		get_normal_from_plane(t_figure *fig, t_point *point);

t_square		*square_create(t_point *center, t_vector *normal, double size);
void			get_basis_of_square(t_vector *normal, t_vector *vec1,
					t_vector *vec2);
t_vector		get_normal_from_square(t_figure *fig, t_point *point);
t_triangle		*triangle_create(t_point *p1, t_point *p2, t_point *p3);
t_vector		get_normal_from_triangle(t_figure *fig, t_point *point);

t_cylinder		*cylinder_create(t_vector dir, double dh[2],
					t_point center);
t_vector		get_normal_from_cylinder(t_figure *fig, t_point *point);

#endif
