/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:51:04 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:24:18 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

static int	pow_num(int k, int n)
{
	int	i;

	i = 1;
	while (n-- > 0)
	{
		i *= k;
	}
	return (i);
}

static int	assignment_int(int *a, int b)
{
	*a = b;
	return (*a);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		cp;
	int		i;
	char	printable;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		i = 1;
		cp = n;
		while (assignment_int(&cp, cp / 10) != 0)
			i++;
		while (--i + 1)
		{
			printable = (n / pow_num(10, i)) % 10 + 48;
			write(fd, &printable, 1);
		}
	}
}
