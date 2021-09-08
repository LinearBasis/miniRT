/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:52:09 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:44:08 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\v');
}

void	skip_spaces(char *str, int *i)
{
	while (str && ft_isspace(str[*i]))
		(*i)++;
}

int	is_on_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set && set[++i])
		if (set[i] == c || (set[i] == ' ' && ft_isspace(c)))
			return (1);
	return (0);
}

int	skip_double_ends(char *str, int *i, char *ends)
{
	if (!str)
		return (0);
	if (str[*i] == '-')
		(*i)++;
	if (!ft_isdigit(str[*i]))
		return (0);
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (is_on_set(str[*i], ends) || str[*i] == 0)
		return (1);
	else if (str[*i] == '.' && ft_isdigit(str[*i + 1]))
		(*i)++;
	else
		return (0);
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (is_on_set(str[*i], ends) || str[*i] == 0)
		return (1);
	return (0);
}

int	skip_int_ends(char *str, int *i, char *ends)
{
	int	num;
	int	prev;

	num = 0;
	if (!str)
		return (0);
	if (str[*i] == '-')
		(*i)++;
	if (!ft_isdigit(str[*i]))
		return (0);
	while (ft_isdigit(str[*i]))
	{
		prev = num;
		num = num * 10 + str[*i] - '0';
		(*i)++;
		if (prev > num)
			return (0);
	}
	if (is_on_set(str[*i], ends) || str[*i] == 0)
		return (1);
	return (0);
}
