/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:00:47 by dnicki            #+#    #+#             */
/*   Updated: 2021/08/27 16:59:28 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	skip_double(char *str, int *i)
{
	return (skip_double_ends(str, i, " "));
}

int	skip_int(char *str, int *i)
{
	return (skip_int_ends(str, i, " "));
}

double	ft_atof(char *str)
{
	double	ans;
	double	k;
	int		p;
	int		sign;

	p = 0;
	ans = 0;
	sign = 1;
	if (str[p] == '-')
	{
		sign = -1;
		p++;
	}
	while (ft_isdigit(str[p]))
		ans = (ans * 10) + str[p++] - '0';
	if (str[p] != '.')
		return (ans * sign);
	p++;
	k = 1;
	while (ft_isdigit(str[p]))
	{
		k /= 10;
		ans += k * (str[p++] - '0');
	}
	return (ans * sign);
}

int	str_find_in_begin(char *str, char *find)
{
	int	i;

	i = 0;
	if (!str || !find)
		return (0);
	while (str[i] != ' ')
	{
		if (str[i] != find[i])
			return (0);
		i++;
	}
	if (find[i] == 0 && str[i] == ' ')
	{
		return (1);
	}
	return (0);
}
