/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:36:52 by dnicki            #+#    #+#             */
/*   Updated: 2021/08/27 16:54:07 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

int				create_rgb(int r, int g, int b);
t_color			color_create(int r, int g, int b);
t_color			color_sum(t_color color1, t_color color2);
t_color			color_prod(t_color color, double k);
int				color_get_int(t_color rgb);

#endif
