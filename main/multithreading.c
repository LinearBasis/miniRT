/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:05:27 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 18:22:22 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

t_thread_data	*thread_data_create(int num, int i, t_scene *scene, t_data *img)
{
	t_thread_data	*ans;

	ans = (t_thread_data *)malloc(sizeof(t_thread_data));
	if (!ans)
		return (ans);
	ans->i = i;
	ans->num_of_threads = num;
	ans->scene = scene;
	ans->img = img;
	return (ans);
}

void	*func_to_thread(void *thread_data)
{
	t_thread_data	data;
	t_data			*img;
	int				color;
	int				j;

	if (thread_data == NULL)
		pthread_exit(NULL);
	data = *(t_thread_data *)thread_data;
	img = data.img;
	while (data.i < data.scene->width)
	{
		j = 0;
		while (j < data.scene->height)
		{
			color = get_color_of_pixel_in_scene(data.i, j, data.scene);
			if (color == -1)
				pthread_exit(NULL);
			my_mlx_pixel_put(img, data.i, j, color);
			j++;
		}
		data.i += data.num_of_threads;
	}
	free(thread_data);
	pthread_exit(thread_data);
}
