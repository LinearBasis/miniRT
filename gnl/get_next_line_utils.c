/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <dnicki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:34:18 by dnicki            #+#    #+#             */
/*   Updated: 2021/04/14 15:04:48 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_headers.h"

char	*ft_strjoin_all_clear(char *s1, char *s2)
{
	char	*ans;
	int		len1;
	int		len2;

	if (!s1 || !s2)
	{
		if (s1)
			free(s1);
		if (s2)
			free(s2);
		return (NULL);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ans = malloc((len1 + len2 + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	ans[0] = 0;
	ft_strlcat(ans, s1, len1 + 1);
	ft_strlcat(ans, s2, len1 + len2 + 1);
	free(s1);
	free(s2);
	return (ans);
}
