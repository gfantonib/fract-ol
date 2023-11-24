/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:58:28 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/24 19:15:40 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_fractol.h"

int	ft_point_validation(t_point a)
{
	return (
		a.x < MARGIN * SIZE || 
		a.x > SIZE - MARGIN * SIZE || 
		a.y < MARGIN * SIZE || 
		a.y > SIZE - MARGIN * SIZE
	);
}

void	ft_colorize(t_fractal *fr, t_point a, double t)
{
	int32_t	color;

	if (fr->decider == 1)
		t = (double)(a.x * a.y) / (SIZE * SIZE);
	else if (fr->decider == 2)
		t = (double)(a.x + a.y) / (SIZE * 2);
	else if (fr->decider == 3)
		t *= t;
	else if (fr->decider == 4)
		t = sqrt(t);
	color = ft_bernstein_pinsky(t);
	if (!ft_point_validation(a))
		mlx_put_pixel(fr->canvas, a.x, a.y, color);
}

void	ft_bresenham_h(t_point a, int32_t dx, int32_t dy, t_fractal *fractal)
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
		ft_colorize(fractal, a, (double)i / abs(dy));
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
		ft_colorize(fractal, a, (double)i / abs(dy));
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
}
