/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:02:34 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/22 13:26:20 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTITHREAD_H
# define MULTITHREAD_H

# include <pthread.h>
# include "scene.h"
# define THREADS 128

typedef struct s_thread_data
{
	int			num_of_threads;
	int			i;
	t_scene		*scene;
	t_data		*img;
}				t_thread_data;

t_thread_data	*thread_data_create(int num, int i,
					t_scene *scene, t_data *img);
void			*func_to_thread(void *thread_data);

#endif
