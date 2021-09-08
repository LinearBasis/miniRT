/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:55:09 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:38:24 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	is_good_brightness(double br)
{
	return (br >= 0 && br <= 1);
}

int	is_good_ambient(t_ambient *ambient)
{
	return (is_good_brightness(ambient->brightness)
		&& is_good_color(&(ambient->color)));
}
