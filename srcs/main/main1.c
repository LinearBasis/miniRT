/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:22:16 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 20:16:24 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	key_hook(int keycode, t_for_hook *asd)
{
	if (keycode == KEY_RIGHT_ARROW || keycode == KEY_D)
	{
		if (asd->scene->cameras != asd->scene->cameras->next)
		{
			asd->scene->cameras = asd->scene->cameras->next;
			if (cast_all(asd->scene, asd->img, THREADS) == -1)
				return (-1);
			mlx_put_image_to_window(asd->mlx, asd->win, asd->img->img, 0, 0);
		}
	}
	if (keycode == KEY_LEFT_ARROW || keycode == KEY_A)
	{
		if (asd->scene->cameras != asd->scene->cameras->prev)
		{
			asd->scene->cameras = asd->scene->cameras->prev;
			if (cast_all(asd->scene, asd->img, THREADS) == -1)
				return (-1);
			mlx_put_image_to_window(asd->mlx, asd->win, asd->img->img, 0, 0);
		}
		mlx_put_image_to_window(asd->mlx, asd->win, asd->img->img, 0, 0);
	}
	if (keycode == KEY_ESC)
		_close(asd);
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i])
		i++;
	return ((int)str1[i] - (int)str2[i]);
}

int	args_good(int argc, char *argv[], int *is_save)
{
	*is_save = 0;
	if (argc == 2)
		return (1);
	if (argc == 3 && (argc == 3 && !ft_strcmp("--save", argv[2])))
	{
		*is_save = 1;
		return (1);
	}
	printf("args error\n");
	return (0);
}

int	solution(t_data *img_cpy, t_scene *scene_cpy, t_for_hook *hook_cpy,
	int is_save, char *argv[])
{
	t_data		img;
	t_scene		scene;
	t_for_hook	hook;

	img = *img_cpy;
	scene = *scene_cpy;
	hook = *hook_cpy;
	hook.win = mlx_new_window(hook.mlx, scene.width, scene.height, "miniRT");
	img.img = mlx_new_image(hook.mlx, scene.width, scene.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (cast_all(&scene, &img, THREADS) == -1)
	{
		scene_clear(&scene);
		return (-1);
	}
	hook = fill_for_hook(&scene, &img, hook.mlx, hook.win);
	if (is_save)
		screenshot(&scene, &img, &hook, argv);
	mlx_put_image_to_window(hook.mlx, hook.win, img.img, 0, 0);
	mlx_key_hook(hook.win, key_hook, &hook);
	mlx_hook(hook.win, 17, 0, _close, &hook);
	mlx_loop(hook.mlx);
	return (1);
}
