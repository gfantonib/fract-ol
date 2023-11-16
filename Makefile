NAME	:= sierpinsky
CFLAGS	:= -Ofast -g #-Wextra -Wall -Werror -Wunreachable-code 
LIBMLX	:= ./MLX42

HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= \
	   ./sierpinsky.c \
	   ./ft_trans.c \
		
OBJS	:= \
	   ./sierpinsky.o \
	   ./ft_trans.o \


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
