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

void	ft_sierpinsky(void *param)
{
	uint32_t color = ft_pixel(255, 255, 255, 255);

	t_point	a;
	t_point	b;

	double	m;
	int32_t	y;
	int32_t	dis;

	int32_t	del_e;
	int32_t	del_ne;

	int32_t	dx;
	int32_t	dy;

	a.x = 0;
	a.y = 800;

	b.x = 800;
	b.y = 0;

	dx = b.x - a.x;
	dy = b.y - a.y;

	m = 1.0 * dy / dx;

	dis = 2 * dy - dx;

	del_e = 2 * abs(dy);
	del_ne = 2 * (abs(dy) - abs(dx));

	if (m < 0)
		ft_opossite(a.y, b.y);
	if (m > 1)
		ft_swap(a, b);

	while (a.x <= b.x)
	{
		if (dis <= 0)
		{
			dis = dis + del_e;
			a.x = a.x + 1;
		}
		else if (dis > 0)
		{
			dis = dis + del_ne;
			a.y = a.y + 1;
			a.x = a.x + 1;
		}
		if (m < 0)
			if (m < 0)
		ft_opossite(a.y, b.y);
			if (m > 1)
		ft_swap(a, b);

		mlx_put_pixel(image, a.x, a.y, color);
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
	if (!(image = mlx_new_image(mlx, 800, 800)))
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
