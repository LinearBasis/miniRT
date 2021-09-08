/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:33:44 by dnicki            #+#    #+#             */
/*   Updated: 2021/08/27 17:01:51 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int			min(int a, int b);
int			max(int a, int b);
double		maxlf(double a, double b);
double		minlf(double a, double b);
double		ft_atof(char *str);
int			str_find_in_begin(char *str, char *find);
int			ft_isspace(char c);
void		skip_spaces(char *str, int *i);
int			skip_double_ends(char *str, int *i, char *ends);
int			skip_int_ends(char *str, int *i, char *ends);
int			skip_double(char *str, int *i);
int			skip_int(char *str, int *i);
int			read_one_int_and_skip_ends(char *str, int *index, int *num,
				char *ends);
int			read_one_double_and_skip_ends(char *str, int *index, double *num,
				char *ends);
int			is_comment_or_end(char *str, int *i);
int			read_vector(char *str, int *index, t_vector *vec);
int			read_color(char *str, int *index, t_color *color);

#endif
