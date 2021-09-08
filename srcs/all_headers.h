/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_headers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:30:22 by dnicki            #+#    #+#             */
/*   Updated: 2021/09/08 20:22:45 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_HEADERS_H
# define ALL_HEADERS_H
# define DEBUG1
# include "../headers/vector.h"
# include "../headers/list.h"
# include "../headers/figures.h"
# include "../headers/scene.h"
# include "../headers/intersections.h"
# include "../headers/color.h"
# include "../headers/utils.h"
# include "../headers/libft.h"
# include "../headers/get_next_line.h"
# include "../headers/parser.h"
# include "../headers/multithread.h"
# include "../headers/screen.h"

# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define KEY_RIGHT_ARROW 124
# define KEY_LEFT_ARROW 123
# define KEY_D 2
# define KEY_A 0 
# define KEY_ESC 53

typedef struct s_for_hook
{
	t_scene	*scene;
	void	*win;
	void	*mlx;
	t_data	*img;
}				t_for_hook;

t_for_hook		fill_for_hook(t_scene *scene, t_data *img, void *mlx,
					void *win);
int				get_color_of_pixel_in_scene(int i, int j, t_scene *scene);
int				get_next_line(int fd, char **line);
int				get_camera_begin(t_scene *scene);
t_vector		get_camera_ray(t_scene *scene, int i, int j);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				cast_all(t_scene *scene, t_data *img, int num_of_threads);
t_color			get_dli(t_scene *scene, t_point *dot, t_figure *fig);
void			screenshort_create(t_scene *scene, t_data img);

int				_close(t_for_hook *asd);
void			screenshot(t_scene *scene, t_data *img, t_for_hook *for_close, char *argv[]);

int				ass_int(int *a, int b);
double			ass_double(double *a, double b);
t_list			*ass_lst(t_list **a, t_list *b);

int				ft_strcmp(char *str1, char *str2);
int				args_good(int argc, char *argv[], int *is_save);
int				solution(t_data *img_cpy, t_scene *scene_cpy,
					t_for_hook *hook_cpy, int is_save, char *argv[]);

#endif