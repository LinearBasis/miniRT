#include <stdlib.h>
#include "../../headers/libft.h"

char	*ft_strdup(char *str)
{
	int		a;
	char	*ans;

	a = ft_strlen(str);
	ans = (char*)malloc(sizeof(char) * (a + 1));
	ans[a] = 0;
	while (a-- > 0)
	{
		ans[a] = str[a];
	}
	return (ans);
}