/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_objects_to_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:08:12 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:36:11 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

static int	create_and_assignment(t_list **lst, void *addr)
{
	*lst = list_create(addr);
	if (lst == NULL)
		return (0);
	return (1);
}

int	scene_add_figure(t_scene *scene, t_figure *fig)
{
	t_list		*lst;

	if (!fig || !create_and_assignment(&lst, fig))
		return (0);
	list_push_back(&(scene->figures), lst);
	return (1);
}

int	scene_add_camera(t_scene *scene, t_camera *camera)
{
	t_list		*lst;

	if (!camera || !create_and_assignment(&lst, camera))
		return (0);
	list_push_back(&(scene->cameras), lst);
	return (1);
}

int	scene_add_light(t_scene *scene, t_light *light)
{
	t_list	*lst;

	if (!light || !create_and_assignment(&lst, light))
		return (0);
	list_push_back(&(scene->lights), lst);
	return (1);
}
