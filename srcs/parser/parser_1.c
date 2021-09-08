/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:40:19 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 19:42:13 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	parse_one_string(t_scene *scene, char *str)
{
	int		flag;

	flag = str[0] == '#' || str[0] == 0;
	if (str_find_in_begin(str, "R"))
		flag = parse_to_scene_resolution(scene, str);
	else if (str_find_in_begin(str, "A"))
		flag = parse_to_scene_ambient(scene, str);
	else if (str_find_in_begin(str, "c"))
		flag = parse_to_scene_camera(scene, str);
	else if (str_find_in_begin(str, "l"))
		flag = parse_to_scene_light(scene, str);
	else if (str_find_in_begin(str, "sp"))
		flag = parse_to_scene_sphere(scene, str);
	else if (str_find_in_begin(str, "pl"))
		flag = parse_to_scene_plane(scene, str);
	else if (str_find_in_begin(str, "sq"))
		flag = parse_to_scene_square(scene, str);
	else if (str_find_in_begin(str, "cy"))
		flag = parse_to_scene_cylinder(scene, str);
	else if (str_find_in_begin(str, "tr"))
		flag = parse_to_scene_triangle(scene, str);
	free(str);
	return (flag);
}

int	parse_file(t_scene *scene, int fd)
{
	char	*str;
	int		flag;

	while (ass_int(&flag, get_next_line(fd, &str)) >= 0)
	{
		if (!parse_one_string(scene, str))
		{
			scene_clear(scene);
			return (0);
		}
		if (flag == 0)
			return (1);
	}
	if (flag == -1)
		scene_clear(scene);
	return (flag != -1);
}

int	parse(t_scene *scene, char *str)
{
	int	fd;
	int	len;

	if (!scene || !str)
		return (0);
	len = ft_strlen(str);
	if (str[len - 1] != 't' || str[len - 2] != 'r' || str[len - 3] != '.')
	{
		printf("name error\n");
		return (0);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("file opening error\n");
		return (0);
	}
	return (parse_file(scene, fd));
}
