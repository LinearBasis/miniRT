/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:34:38 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 19:59:35 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	get_camera_begin(t_scene *scene)
{
	t_camera	*cam;
	t_point		p;

	cam = scene->cameras->data;
	get_basis_of_square(&(cam->dir), &cam->basis_y, &cam->basis_x);
	cam->basis_x = vec_mult(tan(cam->fov * M_PI / 360)
			* scene->width / scene->height, cam->basis_x);
	cam->basis_y = vec_mult(tan(cam->fov * M_PI / 360), cam->basis_y);
	if (cam->dir.z > 0)
	{
		cam->basis_y = vec_mult(-1, cam->basis_y);
		cam->basis_x = vec_mult(-1, cam->basis_x);
	}
	p = vec_sum(cam->center, cam->dir);
	p = vec_sum(p, vec_mult(-1, cam->basis_x));
	p = vec_sum(p, vec_mult(-1, cam->basis_y));
	cam->begin = p;
	cam->basis_x = vec_mult(2., cam->basis_x);
	cam->basis_y = vec_mult(2, cam->basis_y);
	return (1);
}

t_vector	get_camera_ray(t_scene *scene, int i, int j)
{
	t_camera	*cam;
	t_vector	ans;
	t_vector	basis_sum;

	cam = scene->cameras->data;
	basis_sum = vec_sum(vec_mult((i + 0.5) / scene->width, cam->basis_x),
			vec_mult((j + 0.5) / scene->height, cam->basis_y));
	ans = vec_normalize(vec_dif(vec_sum(cam->begin, basis_sum), cam->center));
	return (vec_normalize(ans));
}
