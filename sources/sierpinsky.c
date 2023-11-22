/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:10:38 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/22 10:13:42 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_point	ft_middle(t_point a, t_point b)
{
	t_point	c;

	c.x = (a.x + b.x) / 2;
	c.y = (a.y + b.y) / 2;
	return (c);
}

void	ft_draw_triangle(t_fractal *fr, t_point a, t_point b, t_point c)
{
	ft_bresenham(a, b, fr);
	ft_bresenham(b, c, fr);
	ft_bresenham(c, a, fr);
}

void	ft_sierpinsky(t_point abc[], int n, t_fractal *fr)
{
	t_point	tmp[3];

	tmp[0] = abc[0];
	tmp[1] = abc[1];
	tmp[2] = abc[2];
	if (n > 0)
	{
		ft_draw_triangle(fr, tmp[0], tmp[1], tmp[2]);
		abc[0] = tmp[0];
		abc[1] = ft_middle(tmp[0], tmp[1]);
		abc[2] = ft_middle(tmp[0], tmp[2]);
		ft_sierpinsky(abc, n - 1, fr);
		abc[0] = ft_middle(tmp[0], tmp[1]);
		abc[1] = tmp[1];
		abc[2] = ft_middle(tmp[1], tmp[2]);
		ft_sierpinsky(abc, n - 1, fr);
		abc[0] = ft_middle(tmp[0], tmp[2]);
		abc[1] = ft_middle(tmp[1], tmp[2]);
		abc[2] = tmp[2];
		ft_sierpinsky(abc, n - 1, fr);
	}
}
