#include "./sierpinsky.h"

void	ft_trans(t_point *a, t_point *b)
{
	a->x = a->x + 400;
	a->y = ((-1) * a->y) + 400;

	b->x = b->x + 400;
	b->y = ((-1) * b->y) + 400;
}