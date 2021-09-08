/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:38:29 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:24:45 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		lenstr;
	char	*ans;

	i = 0;
	if (!s)
		return (NULL);
	lenstr = ft_strlen(s);
	if (len < 0)
		return (NULL);
	len = min(len, lenstr - start);
	ans = (char *)malloc(sizeof(char) * (1 + len));
	if (!ans)
		return (NULL);
	while (i < len && start + i < lenstr)
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = 0;
	return (ans);
}
