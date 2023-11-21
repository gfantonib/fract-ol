/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artists_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:28:41 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/21 12:28:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_fractol.h"

void	ft_classic_artist(void *param)
{
	t_fractal	*fr;
	int			n;
	
	fr = param;
	n = fr->iter_max;
	ft_sierpinsky(fr->pinsky.a, fr->pinsky.b, fr->pinsky.c, n, fr);
}

void	ft_artist(void *param)
{
	t_fractal	*fractal;
	uint32_t	color;
	t_complex	c;
	uint32_t	w;
	uint32_t	h;

	w = 0;
	fractal = param;
	while (w < fractal->canvas->width)
	{
		h = 0;
		while (h < fractal->canvas->height)
		{
			ft_trans(&c, fractal, w, h);
			color = fractal->f(fractal, &c);
			mlx_put_pixel(fractal->canvas, w, h, color);
			h++;
		}
		w++;
	}
}