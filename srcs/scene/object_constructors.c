/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:08:51 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 19:50:45 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_camera	*camera_create(t_point *center, t_vector *dir, double fov)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->center = *center;
	cam->dir = *dir;
	cam->fov = fov;
	return (cam);
}

t_light	*light_create(t_point *center, t_color *color, double brightness)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->center = *center;
	light->color = *color;
	light->brightness = brightness;
	return (light);
}

void	*id_to_normal_function(int fig_id)
{
	if (fig_id == SPHERE)
		return (get_normal_from_sphere);
	if (fig_id == PLANE)
		return (get_normal_from_plane);
	if (fig_id == SQUARE)
		return (get_normal_from_square);
	if (fig_id == CYLINDER)
		return (get_normal_from_cylinder);
	if (fig_id == TRIANGLE)
		return (get_normal_from_triangle);
	else
		return (NULL);
}

t_figure	*figure_create(int fig_id, t_color *color, void *obj)
{
	t_figure	*fig;

	fig = (t_figure *)malloc(sizeof(t_figure));
	if (!fig)
		return (NULL);
	fig->fig_id = fig_id;
	fig->color = *color;
	fig->get_normal_vec = id_to_normal_function(fig_id);
	fig->obj = obj;
	return (fig);
}
