/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:35:25 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/21 12:50:51 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_fractol.h"

uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c)
{
	t_complex		z;
	uint32_t		color;
	double			aux;
	unsigned int	n;

	z.real = 0;
	z.i = 0;
	n = 0;
	while (n < fractal->iter_max)
	{
		aux = z.i;
		z.i = (2.0 * z.real * z.i) + c->i; 
		z.real = ((z.real * z.real) - (aux * aux)) + c->real; 
		if (((z.real * z.real) + (z.i * z.i)) > 4.0)
			break ;
		n++;
	}
	if (n == fractal->iter_max)
		color = ft_pixel(0x00, 0x00, 0x00, 0xFF);
	else 
		color = ft_bernstein_poly(n, fractal);
	return (color);
}

uint32_t	ft_julia(t_fractal *fractal, t_complex *pixel)
{
	t_complex		z;
	uint32_t		color;
	double			aux;
	unsigned int	n;

	z.real = pixel->real;
	z.i = pixel->i;
	n = 0;
	while (n < fractal->iter_max)
	{
		aux = z.i;
		z.i = (2.0 * z.real * z.i) + fractal->julia_i; 
		z.real = ((z.real * z.real) - (aux * aux)) + fractal->julia_r; 
		if (((z.real * z.real) + (z.i * z.i)) > 4.0)
			break ;
		n++;
	}
	if (n == fractal->iter_max)
		color = ft_pixel(0x00, 0x00, 0x00, 0xFF);
	else 
		color = ft_bernstein_poly(n, fractal);
	return (color);
}
