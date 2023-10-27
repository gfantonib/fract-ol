#include <stdio.h>

typedef struct	s_complex
{
	double		real;
	double		i;
}			t_complex;

double	ft_power(double number)
{
	number = number * number;
	return (number);
}

void	ft_maldelbrot_function(t_complex *z, t_complex *c)
{
	unsigned int	n;
	double		aux;

	printf("Z1 = Z0 + c\n");
	z->real = c->real;
	z->i = c->i;
	printf("Z1 = (%f, %f)\n", z->real, z->i);

	n = 0;
	while (n < 10)
	{
		//z = z + c;
		printf("Z%d = Z%d + c\n", n + 2, n + 1);
		aux = z->i;
		z->i = (2 * z->real * z->i) + c->i; 
		z->real = (ft_power(z->real) - ft_power(aux)) + c->real; 
		printf("Z%d = (%f, %f)\n", n + 2, z->real, z->i);
		n++;
	}
}

int	main(void)
{
	t_complex	z;
	t_complex	c;

	z.real = 0;
	z.i = 0;

	c.real = -1;
	c.i = 0;

	ft_maldelbrot_function(&z, &c);
	return (0);
}

