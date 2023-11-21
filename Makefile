NAME		:= fractol
BONUS_NAME 	:= fractol_bonus

CFLAGS	:= -Ofast -Wextra -Wall -Werror -Wunreachable-code
LIBMLX	:= ./includes/MLX42
HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	:= \
		./sources/main.c \
		./sources/utils.c \
		./sources/inits.c \
		./sources/sets.c \
		./sources/hooks.c \
		./sources/check_error.c \
		./sources/render.c \

BONUS_SRCS	:= \
			./bonus_sources/main_bonus.c \
			./bonus_sources/utils_1_bonus.c \
			./bonus_sources/utils_2_bonus.c \
			./bonus_sources/inits_bonus.c \
			./bonus_sources/sets_bonus.c \
			./bonus_sources/hooks_bonus.c \
			./bonus_sources/check_error_bonus.c \
			./bonus_sources/render_bonus.c \
			./bonus_sources/sierpinsky_bonus.c \
			./bonus_sources/artists_bonus.c \
			./bonus_sources/bresenham_bonus.c
		
OBJS	:= $(SRCS:%.c=%.o)

BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBS) $(HEADERS) -o $(BONUS_NAME)

bonus: libmlx $(BONUS_NAME)

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

bre: fclean bonus

.PHONY: all clean fclean re libmlx
