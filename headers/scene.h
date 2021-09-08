/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:14:30 by dnicki            #+#    #+#             */
/*   Updated: 2021/08/27 15:31:51 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "list.h"

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_ambient
{
	t_color		color;
	double		brightness;
}				t_ambient;

typedef struct s_camera
{
	t_point		center;
	t_vector	dir;
	double		fov;
	t_vector	basis_x;
	t_vector	basis_y;
	t_point		begin;
}				t_camera;

typedef struct s_light
{
	t_point		center;
	double		brightness;
	t_color		color;
}				t_light;

typedef struct s_scene
{
	int			height;
	int			width;
	t_ambient	ambient;

	t_list		*lights;
	t_list		*cameras;
	t_list		*figures;
}				t_scene;

t_ambient		ambient_create(t_color color, double br);
t_scene			scene_create(void);
int				scene_add_figure(t_scene *scene, t_figure *fig);
int				scene_add_camera(t_scene *scene, t_camera *camera);
int				scene_add_light(t_scene *scene, t_light *light);
void			scene_clear(t_scene *scene);
void			ambient_print(t_ambient amb);
void			scene_print(t_scene scene);

t_camera		*camera_create(t_point *center, t_vector *dir, double fov);
t_light			*light_create(t_point *center, t_color *color,
					double brightness);
t_figure		*figure_create(int fig_id, t_color *color, void *obj);

int				is_good_color(t_color *color);
int				is_good_ambient(t_ambient *ambient);
int				is_good_brightness(double br);
int				is_good_radius(double radius);
int				is_good_fov(double fov);
int				is_good_dir(t_vector *dir);
int				is_good_scene(t_scene *scene);

#endif
