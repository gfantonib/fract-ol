NAME	:= fractol
CFLAGS	:= -Ofast -g #-Wextra -Wall -Werror -Wunreachable-code 
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= \
	   ./sources/main.c \
	   ./sources/utils.c \
	   ./sources/inits.c \
	   ./sources/sets.c \
	   ./sources/libft.c \
	   ./sources/hooks.c \
		
OBJS	:= \
	   ./sources/main.o \
	   ./sources/utils.o \
	   ./sources/inits.o \
	   ./sources/sets.o \
	   ./sources/libft.o \
	   ./sources/hooks.o \


all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
