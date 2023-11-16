#include "./sierpinsky.h"

static mlx_image_t* image;

// -----------------------------------------------------------------------------


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_bresenham(t_point a, t_point b)
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
			mlx_put_pixel(image, a.x, a.y, color);
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
			mlx_put_pixel(image, a.x, a.y, color);
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

void ft_sierpinsky(t_point a, t_point b, t_point c, uint32_t n)
{
    // Lambda function which returns the middle of two point
    //auto Middle = [](Point A, Point B) { return Point((A.x+B.x)/2, (A.y+B.y)/2) ; };

    if(n > 0)
	{
        // Draw triangle
        //window.draw(Triangle(A,B,C).get()) ;
        // Draw three sub-triangles in the triangle
		ft_bresenham(a, b);
		ft_bresenham(b, c);
		ft_bresenham(c, a);

        ft_sierpinsky(a, ft_middle(a, b), ft_middle(a, c), n-1);
        ft_sierpinsky(ft_middle(a, b), b, ft_middle(b, c), n-1);
        ft_sierpinsky(ft_middle(a, c), ft_middle(b, c), c, n-1);
    }
    return ; 
}

	
void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

void	ft_init(void *param)
{
	t_point a;
	t_point b;
	t_point c;

	uint32_t n = 9;

	a.x = SIZE / 2;
	a.y = 25;

	b.x = 25;
	b.y = SIZE - 25;

	c.x = SIZE - 25;
	c.y = SIZE - 25;

	ft_sierpinsky(a, b, c, n);
}

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(SIZE, SIZE, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, SIZE, SIZE)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_init, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
