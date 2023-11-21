/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:27:44 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/21 12:36:19 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../includes/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# define SIZE 800
# define STEP 100

typedef struct	s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_sierpinsky
{
	t_point a;
	t_point b;
	t_point c;
}		t_sierpinsky;

typedef struct s_complex
{
	double		real;
	double		i;
}		t_complex;

typedef struct s_channel
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}	t_channel;

typedef struct s_fractal
{
	const char			*name;
	mlx_t				*mlx;
	mlx_image_t			*canvas;
	void				(*init)(struct s_fractal *fractal, 
			mlx_t *mlx, mlx_image_t *canvas);
	unsigned int		(*f)(struct s_fractal *fractal, t_complex *c);
	uint32_t			iter_max;
	double				axis_len;
	double				trans;
	t_complex			limit;
	double				julia_r;
	double				julia_i;
	char				julia_c;
	t_channel			ch;
	t_sierpinsky		pinsky;
}	t_fractal;

int			ft_check_error(int argc, const char **argv, t_fractal *fractal);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_render(t_fractal *fractal, const char *name);

void		mandelbrot_init(t_fractal *fractal, mlx_t *mlx, 
				mlx_image_t *canvas);
void		julia_init(t_fractal *fractal, mlx_t *mlx, mlx_image_t *canvas);

void		ft_set_julia_const(t_fractal *fractal);
void		ft_trans(t_complex *c, t_fractal *fractal, uint32_t w, uint32_t h);

uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c);
uint32_t	ft_julia(t_fractal *fractal, t_complex *pixel);
uint32_t	ft_bernstein_poly(uint32_t n, t_fractal *fractal);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_zoom(double xdelta, double ydelta, void *param);
void		ft_joystick(void *param);
void		ft_swapp(t_fractal *fractal);

#endif
