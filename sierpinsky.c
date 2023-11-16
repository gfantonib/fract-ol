#include "./sierpinsky.h"

static mlx_image_t* image;

// -----------------------------------------------------------------------------


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	for (int32_t i = 0; i < image->width; ++i)
	{
		for (int32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

int	ft_middle(int x1, int x2)
{
	int	med;
	med = (x1 + x2) / 2;
	return (med);
}

void sierpinski_triangle(t_point a, t_point b, t_point c, int n)
{
    // Lambda function which returns the middle of two point
    //auto Middle = [](Point A, Point B) { return Point((A.x+B.x)/2, (A.y+B.y)/2) ; };

    if(n > 0)
	{
        t_point	ab;
		t_point	ac;
		t_point	bc;
		// Draw triangle
        //window.draw(Triangle(A,B,C).get()) ;
        // Draw three sub-triangles in the triangle
		ft_sierpinsky(&a, &b);
		ft_sierpinsky(&b, &c);
		ft_sierpinsky(&c, &a);

        ab.x = ft_middle(a.x, b.x);
		ab.y = ft_middle(a.y, b.y);
		ac.x = ft_middle(a.x, c.x);
		ac.y = ft_middle(a.y, c.y);
		bc.x = ft_middle(b.x, c.x);
		bc.y = ft_middle(b.y, c.y);
		sierpinski_triangle(a, ab, ac, n-1);
        sierpinski_triangle(ab, b, bc, n-1);
        sierpinski_triangle(ac, bc, c, n-1);
    }
    return ; 
}

void	ft_sierpinsky(void *param)
{
	uint32_t color = ft_pixel(255, 255, 255, 255);

	t_point	a;
	t_point	b;

	int32_t	dis;

	int32_t	dx;
	int32_t	dy;

	a.x = 800;
	a.y = 0;

	b.x = 720;
	b.y = 800;

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
	
	mlx_loop_hook(mlx, ft_sierpinsky, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
