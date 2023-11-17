/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:36:52 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/17 09:42:18 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_set_julia_const(t_fractal *fractal)
{
	if (fractal->julia_c == 'a')
	{
		fractal->julia_r = 0.0;
		fractal->julia_i = 0.8;
	}
	else if (fractal->julia_c == 'b')
	{
		fractal->julia_r = 0.355;
		fractal->julia_i = 0.355;
	}
	else if (fractal->julia_c == 'c')
	{
		fractal->julia_r = 0.34;
		fractal->julia_i = -0.05;
	}
	else if (fractal->julia_c == 'd')
	{
		fractal->julia_r = -0.4;
		fractal->julia_i = -0.59;
	}
	else if (fractal->julia_c == 'S')
	{
		fractal->julia_r = -0.8 ;
		fractal->julia_i = 0.156;
	}
}

void	ft_trans(t_complex *c, t_fractal *fractal, uint32_t w, uint32_t h)
{
	c->real = (+1.0) * fractal->trans * w + fractal->limit.real;
	c->i = (-1.0) * fractal->trans * h + fractal->limit.i;
}

uint32_t	ft_bernstein_poly(uint32_t n, t_fractal *fractal)
{
	double		t;
	int32_t		color;
	int32_t		poly[3];
	t_channel	ch;

	ch = fractal->ch;
	t = 1.0 * n / fractal->iter_max;
	poly[0] = 255 * 9.0 * t * (1 - t) * (1 - t) * (1 - t);
	poly[1] = 255 * 17.0 * t * t * (1 - t) * (1 - t);
	poly[2] = 255 * 12.0 * t * t * t * (1 - t);
	color = ft_pixel(poly[ch.r], poly[ch.g], poly[ch.b], 255);
	return (color);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	z;

	z = 0;
	while ((s1[z] != '\0' || s2[z] != '\0') && n--)
	{
		if (s1[z] != s2[z])
			return ((unsigned char)s1[z] - (unsigned char)s2[z]);
		z++;
	}
	return (0);
}
