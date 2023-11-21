#include "../includes/bonus_fractol.h"

// void	ft_bresenham_horizontal(t_point a, int32_t dx, int32_t dy, int32_t dis)
// {
	
// }

// void	ft_bresenham_vertical(t_point a, int32_t dx, int32_t dy, int32_t dis)
// {
	
// }

void	ft_bresenham(t_point a, t_point b, t_fractal *fractal)
{
	uint32_t color = ft_pixel(255, 255, 255, 255);

	int32_t	dis;

	int32_t	dx;
	int32_t	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;

	int32_t i = 0;
	if (abs(dx) > abs(dy))
	{
		dis = (2 * abs(dy)) - abs(dx);
		while (i < abs(dx))
		{
			if (dx < 0)
				a.x = a.x - 1;
			else
				a.x = a.x + 1;
			if (dis < 0)
				dis = dis + 2*abs(dy);
			else
			{
				if (dy < 0)
					a.y = a.y - 1;
				else
					a.y = a.y + 1;
				dis = dis + 2*(abs(dy) - abs(dx));
			}
			i++;
			if (!ft_point_validation(a))
			{
				printf("x=%d, y=%d\n", a.x, a.y);
            	mlx_put_pixel(fractal->canvas, a.x, a.y, color);
			}
		}
	}
	else
	{
		dis = (2 * abs(dx)) - abs(dy);
		while (i < abs(dy))
		{
			if (dy < 0)
				a.y = a.y - 1;
			else
				a.y = a.y + 1;
			if (dis < 0)
				dis = dis + 2*abs(dx);
			else
			{
				if (dx < 0)
					a.x = a.x - 1;
				else 
					a.x = a.x + 1;
				dis = dis + 2*(abs(dx) - abs(dy));
			}
			i++;
			if (!ft_point_validation(a))
			{
				printf("x=%d, y=%d\n", a.x, a.y);
            	mlx_put_pixel(fractal->canvas, a.x, a.y, color);
			}
		}
		
	}
}

t_point ft_middle(t_point a, t_point b)
{
	t_point c;

	c.x = (a.x + b.x) / 2;
	c.y = (a.y + b.y) / 2;

	return (c);
}

void ft_sierpinsky(t_point a, t_point b, t_point c, int n, t_fractal *fractal)
{
    if(n > 0)
	{
		ft_bresenham(a, b, fractal);
		ft_bresenham(b, c, fractal);
		ft_bresenham(c, a, fractal);

        ft_sierpinsky(a, ft_middle(a, b), ft_middle(a, c), n-1, fractal);
        ft_sierpinsky(ft_middle(a, b), b, ft_middle(b, c), n-1, fractal);
        ft_sierpinsky(ft_middle(a, c), ft_middle(b, c), c, n-1, fractal);
    }
    return ; 
}