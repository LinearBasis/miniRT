#include "../all_headers.h"

int	ass_int(int *a, int b)
{
	*a = b;
	return (*a);
}

double	ass_double(double *a, double b)
{
	*a = b;
	return (*a);
}

t_list	*ass_lst(t_list **a, t_list *b)
{
	*a = b;
	return (*a);
}
