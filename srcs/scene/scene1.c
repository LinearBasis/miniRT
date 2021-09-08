/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:54:25 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/22 13:31:11 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	is_good_color(t_color *color)
{
	return (color->b <= 255 && color->r <= 255 && color->g <= 255
		&& color->b >= 0 && color->r >= 0 && color->g >= 0);
}

int	is_good_radius(double radius)
{
	return (radius >= 0);
}

int	is_good_fov(double fov)
{
	return (fov > 0. && fov < 180.);
}

int	is_good_dir(t_vector *dir)
{
	return (fabs(vec_abs(*dir) - 1) < 1E-6);
}

int	is_good_scene(t_scene *scene)
{
	if (!scene)
		return (0);
	if (scene->width <= 0 || scene->height <= 0
		|| scene->ambient.brightness < 0)
		return (0);
	if (!scene->cameras)
		return (0);
	return (1);
}
