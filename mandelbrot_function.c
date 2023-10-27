#include <stdio.h>

typedef struct	s_complex
{
	double		real;
	double		i;
}			t_complex;

//double	ft_power(double number)
//{
//	number = number * number;
//	return (number);
//}

int	main(void)
{
	t_complex	z;
	t_complex	c;
	z.real = 0;
	z.i = 0;
	c.real = -1;
	c.i = 0.23;

	unsigned int	n;
	double		aux;
	n = 0;
	while (n <= 50)
	{
		//z = z + c;
		printf("n = %d: (%f, %f)\n", n, z.real, z.i);
		aux = z.i;
		z.i = (2 * z.real * z.i) + c.i; 
		z.real = ((z.real * z.real) - (aux * aux)) + c.real; 
		n++;
	}
	return (0);
}

