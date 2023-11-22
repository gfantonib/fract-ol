/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:09:18 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/22 10:13:23 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_check_error(int argc, const char **argv, t_fractal *fractal)
{
	if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
	{
		fractal->init = mandelbrot_init;
		return (0);
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "julia"))
	{
		fractal->julia_c = 'S';
		fractal->init = julia_init;
		return (0);
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "sierpinsky"))
	{
		fractal->init = sierpinsky_init;
		return (0);
	}
	if (argc == 3 && !ft_strcmp(argv[1], "julia") && 
		argv[2][0] >= 'a' && argv[2][0] <= 'd')
	{
		fractal->julia_c = argv[2][0];
		fractal->init = julia_init;
		return (0);
	}
	return (1);
}
