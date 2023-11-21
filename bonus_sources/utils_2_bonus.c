/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:03:30 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/21 14:33:52 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_fractol.h"

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

void	ft_swapp(t_fractal *fractal)
{
	uint32_t	aux;

	aux = fractal->ch.r;
	fractal->ch.r = fractal->ch.g;
	fractal->ch.g = fractal->ch.b;
	fractal->ch.b = aux;
}

int	ft_point_validation(t_point a)
{
	return (
		a.x < MARGIN * SIZE || 
		a.x > SIZE - MARGIN * SIZE || 
		a.y < MARGIN * SIZE || 
		a.y > SIZE - MARGIN * SIZE
	);
}
