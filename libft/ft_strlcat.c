/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:20:05 by dnicki            #+#    #+#             */
/*   Updated: 2021/03/24 18:28:50 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ans;

	ans = ft_strlen(dst) + ft_strlen(src);
	if (ft_strlen(dst) > dstsize - 1 || dstsize == 0)
	{
		return (dstsize + ft_strlen(src));
	}
	i = 0;
	j = 0;
	while (dst[i] && i < dstsize && dstsize > 0)
	{
		i++;
	}
	while (i < dstsize - 1 && src[j] && dstsize > 0)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (ans);
}
