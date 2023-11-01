# ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
//#include <cstdint>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 800

typedef struct s_complex
{

	double		real;
	double		i;
}		t_complex;

typedef struct s_fractal
{
	void		(*init)(struct s_fractal *fractal, mlx_t *mlx, mlx_image_t *canvas);
	const char	*name;
	uint32_t	(*f)(struct s_fractal *fractal, t_complex *c);
	uint32_t	iter_max;
	double		axis_len;
	double		a;
	t_complex	b;
	mlx_t		*mlx;
	mlx_image_t	*canvas;

}	t_fractal;


int     	ft_strncmp(const char *s1, const char *s2, size_t n);
void		mandelbrot_init(t_fractal  *fractal, mlx_t *mlx, mlx_image_t *canvas);
void		ft_trans(t_complex *c, t_fractal *fractal, uint32_t w, uint32_t h);
uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c);
uint32_t	ft_bernstein_poly(uint32_t n, uint32_t iter_max);
int32_t 	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	ft_joystick(void *param);

# endif

