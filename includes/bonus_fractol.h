/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractol.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:12:48 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/22 16:47:48 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_FRACTOL_H
# define BONUS_FRACTOL_H

# include "../includes/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# define SIZE 800
# define STEP 100
# define MARGIN 0.03

// @brief Store the value of two int, the x and y coordinates.
// @param x int x;
// @param y int y;
typedef struct s_point
{
	int		x;
	int		y;
}	t_point;
// -----------------------------------------------------------------------------

// @brief Store the value of three points, abc.
// @param a t_point a;
// @param b t_point b;
// @param c t_point c;
typedef struct s_sierpinsky
{
	t_point	a;
	t_point	b;
	t_point	c;
}		t_sierpinsky;
// -----------------------------------------------------------------------------

// @brief Store the value of two doubles, real and i;
// @param real double real;
// @param i double i;
typedef struct s_complex
{
	double		real;
	double		i;
}		t_complex;
// -----------------------------------------------------------------------------

// @brief Store the value of three uint32_t, rgb.
// @param real double real;
// @param r uint32_t r;
// @param g uint32_t g;
// @param b uint32_t b;
typedef struct s_channel
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}	t_channel;
// -----------------------------------------------------------------------------

// @brief Store the value of several item needed to be loaded everywhere.
// @param name const char *name;
// @param *mlx mlx_t *mlx;
// @param *canvas mlx_image_t *canvas;
// @param function void (*init)(struct s_fractal *fractal, 
// mlx_t *mlx, mlx_image_t *canvas);
// @param function unsigned int (*f)(struct s_fractal *fractal, t_complex *c);
// @param iter_max uint32_t iter_max;
// @param axis_len double axis_len;
// @param trans double trans;
// @param limit t_complex	limit;
// @param julia_r double julia_r;
// @param julia_i double julia_i;
// @param julia_c char julia_c;
// @param ch t_channel ch;
// @param pinsk t_sierpinsky pinsky;
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
// -----------------------------------------------------------------------------

// SOURCES/CHECK_ERROR.C

// @brief Validate the parameters placed in command line.
// @param argc Number of parameters.
// @param **argv Double pointer to parameters.
// @param fractal Pointer to object.
int			ft_check_error(int argc, const char **argv, t_fractal *fractal);
// -----------------------------------------------------------------------------

// SOURCES/RENDER.C

// @brief Create window and image and give the name for the init function.
// @param fractal Pointer to object.
// @param name Pointer to the name of the set.
int			ft_render(t_fractal *fractal, const char *name);
// -----------------------------------------------------------------------------

// SOURCES/INIT.C

// @brief Init the values of the object.
// @param *fr pointer to object.
// @param *mlx pointer to window.
// @param *canvas pointer to image.
void		mandelbrot_init(t_fractal *fr, mlx_t *mlx, mlx_image_t *canvas);

// @brief Init the values of the object.
// @param *fractal pointer to object.
// @param *mlx pointer to window.
// @param *canvas pointer to image.
void		julia_init(t_fractal *fractal, mlx_t *mlx, mlx_image_t *canvas);

// @brief Init the values of the object.
// @param *fr pointer to object.
// @param *mlx pointer to window.
// @param *canvas pointer to image.
void		sierpinsky_init(t_fractal *fr, mlx_t *mlx, mlx_image_t *canvas);
// -----------------------------------------------------------------------------

// SOURCES/ARTIST.C

// @brief Iterate pixel per pixel and put its colours in screen.
// @param *param pointer to object.
void		ft_artist(void *param);

// @brief Send three points to siepinsky function.
// @param *param pointer to object.
void		ft_classic_artist(void *param);
// -----------------------------------------------------------------------------

// SOURCES/SETS.C

// @brief Mandelbrot algorithm to check if point belongs or not to the set.
// Initial value of Z is 0.
// The constant is the coordinates of the pixel in imaginary plan.
// @param *fractal pointer to object
// @param *c pointer to point in the imaginary plan
uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c);

// @brief Julia algorithm to check if point belongs or not to the set.
// Initials values of Z are the pixel coordinates in imaginary plan.
// The constant is fixed.
// @param *fractal pointer to object
// @param *c pointer to point in the imaginary plan
uint32_t	ft_julia(t_fractal *fractal, t_complex *pixel);
// -----------------------------------------------------------------------------

// SOURCES/HOOKS.C

// @brief Reduce or increase the axis of the plan. Approach or move away 
// the limit of the axis to the mouse.
// @param xdelta horizontal motion of the scroll (unused).
// @param ydelta vertical motion of the scroll.
// @param *param Pointer to object.
void		ft_zoom(double xdelta, double ydelta, void *param);

// @brief Change image properties by keyeboard commands.
// @param *param Pointer to object.
void		ft_joystick(void *param);

// @brief Approach or move away the points to the mouse.
// Destroy the old image and crate a new one.
// @param xdelta horizontal motion of the scroll (unused).
// @param ydelta vertical motion of the scroll.
// @param *param Pointer to object.
void		ft_pinsky_zoom(double xdelta, double ydelta, void *param);
// -----------------------------------------------------------------------------

// SOURCES/UTILS_1.C

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr(char *str); 
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

// @brief Transform the coordinates of the pixel realm to the imaginary realm.
// @param *c pointer to complex object.
// @param *fractal pointer to object.
// @param w Horizontal value of pixel. 
// @param h Vertical value of pixel.
void		ft_trans(t_complex *c, t_fractal *fractal, uint32_t w, uint32_t h);

// @brief Wonderful function that makes the colors change smooth.
// It dose the right amount of rgb by the value of the iteration.
// @param n number of the iteration.
// @param *fractal pointer to object.
uint32_t	ft_bernstein_poly(uint32_t n, t_fractal *fractal);
// -----------------------------------------------------------------------------

// SOURCES/UTILS_2.C

// @brief Set the possible values for the julia constants used in the algorithm.
// @param *fractal Pointer to object.
void		ft_set_julia_const(t_fractal *fractal);

// @brief Swapp the values of the Bernstein Polyniomials 
// to change the color of the fractal.
// @param *fractal Pointer to object.
void		ft_swapp(t_fractal *fractal);

// @brief Ensures that the given point is inside the image.
// This funtion prevents from "core dump".
// @param a The given point.
int			ft_point_validation(t_point a);
// -----------------------------------------------------------------------------

// SOURCES/SIERPINSKY.C

// @brief Recursive function with three calls that, for each call, 
// change the values of every point but the one that remains fixed.
// @param abc[] List of points (3).
// @param n The number of iterations.
// @param *fr Pointer to object.
void		ft_sierpinsky(t_point abc[], int n, t_fractal *fr);
// -----------------------------------------------------------------------------

// SOURCES/BRESENHAM.C

// @brief Fucking alorithm that draw a line.
// It decides for each iteration the best point to be putted on image
// to follow the "tendence" of the "line".
// @param a Initial point.
// @param b End point.
// @param *fractal Pointer to object.
void		ft_bresenham(t_point a, t_point b, t_fractal *fractal);
// -----------------------------------------------------------------------------

#endif