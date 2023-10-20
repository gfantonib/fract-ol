all: 
	cc -o fractol test.c minilibx_linux/libmlx.a -I ./minilibx-linux/ -lXext -lX11 -lm



