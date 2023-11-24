/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joystick_pinsky_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:19:05 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/24 19:19:46 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_fractol.h"

uint32_t	ft_bernstein_pinsky(double t)
{
	int32_t		color;
	int32_t		poly[3];

	poly[0] = 255 * 9.0 * t * (1 - t) * (1 - t) * (1 - t);
	poly[1] = 255 * 17.0 * t * t * (1 - t) * (1 - t);
	poly[2] = 255 * 12.0 * t * t * t * (1 - t);
	color = ft_pixel(poly[0], poly[1], poly[2], 255);
	return (color);
}

void	ft_mlx_update(t_fractal *fr)
{
	mlx_delete_image(fr->mlx, fr->canvas);
	fr->canvas = mlx_new_image(fr->mlx, SIZE, SIZE);
	mlx_image_to_window(fr->mlx, fr->canvas, 0, 0);
}

void	ft_mlx_key(t_sierpinsky *pinsky, int x_move, int y_move, t_fractal *fr)
{
	pinsky->a.x += x_move;
	pinsky->b.x += x_move;
	pinsky->c.x += x_move;
	pinsky->a.y += y_move;
	pinsky->b.y += y_move;
	pinsky->c.y += y_move;
	ft_mlx_update(fr);
}

void	ft_joystick_pinsky(void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F1))
		fractal->decider = 1;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F2))
		fractal->decider = 2;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F3))
		fractal->decider = 3;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F4))
		fractal->decider = 4;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_F5))
		fractal->decider = 0;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		ft_mlx_key(&fractal->pinsky, 0, -STEP_P, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		ft_mlx_key(&fractal->pinsky, 0, +STEP_P, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		ft_mlx_key(&fractal->pinsky, -STEP_P, 0, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		ft_mlx_key(&fractal->pinsky, +STEP_P, 0, fractal);
}
