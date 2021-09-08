/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:48:45 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:22:09 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	ft_atoi(const char *str)
{
	int	ans;
	int	i;
	int	s;
	int	left;

	i = 0;
	s = 1;
	ans = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		s = -1 + (++i * 0);
	else if ((str[i]) == '+')
		i++;
	left = i;
	while (str[i] && ft_isdigit(str[i]))
	{
		ans = ans * 10 - (str[i] - '0');
		i++;
	}
	if (i - left >= 20)
		return (0 - (s == 1));
	return (-ans * s);
}
