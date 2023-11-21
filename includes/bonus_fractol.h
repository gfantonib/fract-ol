/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractol.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:25:58 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/21 16:06:41 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_FRACTOL_H
# define BONUS_FRACTOL_H

# include "../includes/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# define SIZE 800
# define STEP 100
# define MARGIN 0.03

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_sierpinsky
{
	t_point	a;
	t_point	b;
	t_point	c;
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

// check_error_bonus.c
int			ft_check_error(int argc, const char **argv, t_fractal *fractal);

// bonus_sources/render_bonus.c
int			ft_render(t_fractal *fractal, const char *name);

// bonus_sources/inits_bonus.c
void		mandelbrot_init(t_fractal *fr, mlx_t *mlx, mlx_image_t *canvas);
void		julia_init(t_fractal *fractal, mlx_t *mlx, mlx_image_t *canvas);
void		sierpinsky_init(t_fractal *fr, mlx_t *mlx, mlx_image_t *canvas);

// bonus_sources/artists_bonus.c
void		ft_artist(void *param);
void		ft_classic_artist(void *param);

// bonus_sources/sets_bonus.c
uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c);
uint32_t	ft_julia(t_fractal *fractal, t_complex *pixel);

// bonus_sources/hooks_bonus.c
void		ft_zoom(double xdelta, double ydelta, void *param);
void		ft_joystick(void *param);
void		ft_pinsky_zoom(double xdelta, double ydelta, void *param);

// bonus_sources/utils_1_bonus.c
int			ft_strcmp(const char *s1, const char *s2);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_trans(t_complex *c, t_fractal *fractal, uint32_t w, uint32_t h);
uint32_t	ft_bernstein_poly(uint32_t n, t_fractal *fractal);

// bonus_sources/utils_2_bonus.c
void		ft_set_julia_const(t_fractal *fractal);
void		ft_swapp(t_fractal *fractal);
int			ft_point_validation(t_point a);

// bonus_sources/sierpinsky_bonus.c
// void		ft_sierpinsky(t_point a, t_point b, t_point c, int n, t_fractal *fr);
void		ft_sierpinsky(t_point abc[], int n, t_fractal *fr);

#endif