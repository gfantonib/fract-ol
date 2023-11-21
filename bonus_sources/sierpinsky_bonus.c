/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:28:15 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/21 19:57:48 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_fractol.h"

/* void	ft_bresenham_h(t_point a, int32_t dx, int32_t dy, t_fractal *fractal)
{
	int32_t	i;
	int32_t	dis;

	i = 0;
	dis = (2 * abs(dy)) - abs(dx);
	while (i++ < abs(dx))
	{
		if (dx < 0)
			a.x = a.x - 1;
		else
			a.x = a.x + 1;
		if (dis < 0)
			dis = dis + 2 * abs(dy);
		else
		{
			if (dy < 0)
				a.y = a.y - 1;
			else
				a.y = a.y + 1;
			dis = dis + 2 * (abs(dy) - abs(dx));
		}
		if (!ft_point_validation(a))
			mlx_put_pixel(fractal->canvas, a.x, a.y, 0xFFFFFFF);
	}
}

void	ft_bresenham_v(t_point a, int32_t dx, int32_t dy, t_fractal *fractal)
{
	int32_t	dis;
	int32_t	i;

	i = 0;
	dis = (2 * abs(dx)) - abs(dy);
	while (i++ < abs(dy))
	{
		if (dy < 0)
			a.y = a.y - 1;
		else
			a.y = a.y + 1;
		if (dis < 0)
			dis = dis + 2 * abs(dx);
		else
		{
			if (dx < 0)
				a.x = a.x - 1;
			else 
				a.x = a.x + 1;
			dis = dis + 2 * (abs(dx) - abs(dy));
		}
		if (!ft_point_validation(a))
			mlx_put_pixel(fractal->canvas, a.x, a.y, 0xFFFFFFFF);
	}
}

void	ft_bresenham(t_point a, t_point b, t_fractal *fractal)
{
	int32_t	dx;
	int32_t	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (abs(dx) > abs(dy))
		ft_bresenham_h(a, dx, dy, fractal);
	else
		ft_bresenham_v(a, dx, dy, fractal);
} */

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
