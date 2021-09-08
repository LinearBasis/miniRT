/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:08:30 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 20:17:19 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	_close(t_for_hook *asd)
{
	printf("Destroy scene:\n");
	scene_clear(asd->scene);
	printf("Destroy image:\n");
	mlx_destroy_image(asd->mlx, asd->img->img);
	printf("Destroy window:\n");
	mlx_destroy_window(asd->mlx, asd->win);
	printf("good exit:\n");
	exit(0);
}

t_for_hook	fill_for_hook(t_scene *scene, t_data *img, void *mlx, void *win)
{
	t_for_hook	ans;

	ans.scene = scene;
	ans.mlx = mlx;
	ans.img = img;
	ans.win = win;
	return (ans);
}

int	main(int argc, char *argv[])
{
	t_data		img;
	t_scene		scene;
	t_for_hook	hook;
	int			is_save;

	scene = scene_create();
	hook.mlx = mlx_init();
	if (!args_good(argc, argv, &is_save) || !parse(&scene, argv[1]))
	{
		return (0);
	}
	if (!is_good_scene(&scene))
	{
		printf("Scene is bad\n");
		scene_clear(&scene);
		return (0);
	}
	return (solution(&img, &scene, &hook, is_save, argv));
}
