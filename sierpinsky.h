#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define SIZE 800

typedef struct	s_point
{
	int32_t	x;
	int32_t	y;
}	t_point;

void	ft_trans(t_point *a, t_point *b);
void sierpinski_triangle(t_point a, t_point b, t_point c, int n);


