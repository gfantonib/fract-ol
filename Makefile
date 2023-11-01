NAME	:= fractol
CFLAGS	:= -Ofast -g #-Wextra -Wall -Werror -Wunreachable-code 
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= \
	   ./src/main.c \
	   ./src/utils.c \
	   ./src/inits.c \
	   ./src/sets.c \
	   ./src/libft.c \
	   ./src/hooks.c \
		
OBJS	:= \
	   ./src/main.o \
	   ./src/utils.o \
	   ./src/inits.o \
	   ./src/sets.o \
	   ./src/libft.o \
	   ./src/hooks.o \


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
