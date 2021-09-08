/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:08:26 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 19:43:30 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

static int	return_clear(void *data1, void *data2)
{
	if (data1)
		free(data1);
	if (data2)
		free(data2);
	return (-1);
}

int	cast_ray(t_vector *dir, t_scene *scene)
{
	t_list		*lst;
	t_figure	*fig;
	double		k[2];
	t_vector	p;

	if (!ass_lst(&lst, scene->figures))
		return (0);
	k[0] = INFINITY;
	fig = NULL;
	while (1)
	{
		if (ass_double(&k[1], any_intersect(dir, (t_figure *)lst->data,
					&(((t_camera *)(scene->cameras->data))->center))) < k[0])
		{
			fig = (t_figure *)lst->data;
			k[0] = k[1];
		}
		if ((ass_lst(&lst, lst->next)) == scene->figures)
			break ;
	}
	p = vec_sum(vec_sum(vec_mult(-1E-9, *dir), vec_mult(k[0], *dir)),
			((t_camera *)(scene->cameras->data))->center);
	if (k[0] < INFINITY)
		return (color_get_int(get_dli(scene, &p, fig)));
	return (0);
}

int	get_color_of_pixel_in_scene(int i, int j, t_scene *scene)
{
	t_vector	dir;

	dir = get_camera_ray(scene, i, j);
	return (cast_ray(&dir, scene));
}

static t_thread_data	*assdata(t_thread_data **a, t_thread_data *b)
{
	*a = b;
	return (*a);
}

int	cast_all(t_scene *scene, t_data *img, int num_of_threads)
{
	t_thread_data	*data;
	pthread_t		*tids;
	pthread_attr_t	attr;
	int				i;
	void			*returned;

	i = -1;
	get_camera_begin(scene);
	tids = (pthread_t *)malloc(sizeof(pthread_t) * num_of_threads);
	while (++i < num_of_threads)
	{
		if (!assdata(&data, thread_data_create(num_of_threads, i, scene, img)))
			return (-1);
		pthread_attr_init(&attr);
		if (pthread_create(&tids[i], &attr, func_to_thread, data) < 0)
			return (return_clear(tids, data));
	}
	i = -1;
	while (++i < num_of_threads)
	{
		if (pthread_join(tids[i], &returned) < 0 || returned == NULL)
			return (return_clear(tids, NULL));
	}
	free(tids);
	return (1);
}
