/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:58:08 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 19:41:23 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

static int	all_any_intersect(t_vector *dir, t_list *figures,
	t_vector *origin, double k_light)
{
	double		k;
	t_list		*lst;
	t_figure	*tmp;

	k = INFINITY;
	lst = figures;
	while (1)
	{
		tmp = ((t_figure *)lst->data);
		k = any_intersect(dir, tmp, origin);
		if (k < k_light)
			return (1);
		lst = lst->next;
		if (lst == figures)
			return (0);
	}
}

t_color	get_color_with_light(t_light *light, double k, t_color ans_color)
{
	t_color	light_color;
	t_color	ans;

	light_color = light->color;
	ans = color_sum(color_prod(light_color, k), ans_color);
	return (ans);
}

t_color	_get_color(t_color col1, double k, t_color col2)
{
	return (color_sum(color_prod(col1, k), col2));
}

t_light	get_light_answer_to_dli(t_scene *scene, t_point *dot, t_figure *fig)
{
	t_light		ans;
	t_list		*lst;
	t_vector	from_to;
	t_vector	normal;
	double		k;

	ans.color = color_create(0, 0, 0);
	ans.brightness = scene->ambient.brightness;
	normal = fig->get_normal_vec(fig, dot);
	lst = scene->lights;
	while (lst)
	{
		from_to = vec_normalize(vec_dif(((t_light *)lst->data)->center, *dot));
		if (!all_any_intersect(&from_to, scene->figures, dot,
				vec_abs(vec_dif(((t_light *)lst->data)->center, *dot))))
		{
			k = fabs(vec_scalar_prod(normal, from_to)
					* ((t_light *)lst->data)->brightness);
			ans.color = get_color_with_light(lst->data, k, ans.color);
			ans.brightness += k;
		}
		if (ass_lst(&lst, lst->next) == scene->lights)
			break ;
	}
	return (ans);
}

t_color	get_dli(t_scene *scene, t_point *dot, t_figure *fig)
{
	t_light	ans;

	ans = get_light_answer_to_dli(scene, dot, fig);
	ans.color = color_sum(color_prod(fig->color,
				minlf(1, ans.brightness)), ans.color);
	ans.color = color_sum(color_prod(scene->ambient.color,
				scene->ambient.brightness), ans.color);
	return (ans.color);
}
