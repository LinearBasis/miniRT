/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:56:42 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 19:41:58 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scene.h"

int		parse_to_scene_resolution(t_scene *scene, char *str);
int		parse_to_scene_ambient(t_scene *scene, char *str);
int		parse_to_scene_camera(t_scene *scene, char *str);
int		parse_to_scene_light(t_scene *scene, char *str);
int		parse_to_scene_sphere(t_scene *scene, char *str);
int		parse_to_scene_plane(t_scene *scene, char *str);
int		parse_to_scene_square(t_scene *scene, char *str);
int		parse_to_scene_cylinder(t_scene *scene, char *str);
int		parse_to_scene_triangle(t_scene *scene, char *str);
int		parse(t_scene *scene, char *str);
int		parse_file(t_scene *scene, int fd);
int		parse_one_string(t_scene *scene, char *str);

#endif
