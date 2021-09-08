/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:23:31 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:37:43 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

void	del_fig(void *obj)
{
	t_figure	*fig;

	fig = obj;
	free(fig->obj);
	free(fig);
}

t_ambient	ambient_create(t_color color, double br)
{
	t_ambient	ans;

	ans.color = color;
	ans.brightness = br;
	return (ans);
}

t_scene	scene_create(void)
{
	t_scene	ans;

	ans.height = -1;
	ans.width = -1;
	ans.ambient = ambient_create(color_create(0, 0, 0), -1);
	ans.cameras = NULL;
	ans.figures = NULL;
	ans.lights = NULL;
	return (ans);
}

void	scene_clear(t_scene *scene)
{
	list_clear(&(scene->figures), del_fig);
	list_clear(&(scene->cameras), free);
	list_clear(&(scene->lights), free);
}
