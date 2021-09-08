/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:40:04 by dnicki            #+#    #+#             */
/*   Updated: 2021/08/27 16:33:19 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

static int	create_rgb_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	color_get_int(t_color rgb)
{
	return (create_rgb_int(rgb.r, rgb.g, rgb.b));
}

t_color	color_create(int r, int g, int b)
{
	t_color	ans;

	ans.b = b;
	ans.g = g;
	ans.r = r;
	return (ans);
}

t_color	color_sum(t_color color1, t_color color2)
{
	t_color	ans;

	ans.r = min(color1.r + color2.r, 255);
	ans.g = min(color1.g + color2.g, 255);
	ans.b = min(color1.b + color2.b, 255);
	return (ans);
}

t_color	color_prod(t_color color, double k)
{
	color.r *= k;
	color.g *= k;
	color.b *= k;
	return (color);
}
