NAME		:= fractol
BONUS_NAME 	:= fractol_bonus

CFLAGS	:= -Ofast -Wextra -Wall -Werror -Wunreachable-code
LIBMLX	:= ./includes/MLX42
HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
MK = mkdir -p

SOURCE_PATH = sources/
BONUS_SOURCE_PATH = bonus_sources/

SRCS	:= \
			main.c \
			utils_1.c \
			utils_2.c \
			inits.c \
			sets.c \
			hooks.c \
			check_error.c \
			render.c \
			sierpinsky.c \
			artists.c \
			bresenham.c

BONUS_SRCS	:= \
			main_bonus.c \
			utils_1_bonus.c \
			utils_2_bonus.c \
			inits_bonus.c \
			sets_bonus.c \
			hooks_bonus.c \
			check_error_bonus.c \
			render_bonus.c \
			sierpinsky_bonus.c \
			artists_bonus.c \
			bresenham_bonus.c \
			joystick_pinsky_bonus.c

OBJECTS_PATH = objects
OBJS	:= $(addprefix $(OBJECTS_PATH)/, $(SRCS:%.c=%.o))

BONUS_OBJECTS_PATH = bonus_objects
BONUS_OBJS := $(addprefix $(BONUS_OBJECTS_PATH)/, $(BONUS_SRCS:%.c=%.o))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJECTS_PATH)/%.o: $(SOURCE_PATH)%.c
	@$(MK) $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) "

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BONUS_OBJECTS_PATH)/%.o: $(BONUS_SOURCE_PATH)%.c
	@$(MK) $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) "

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBS) $(HEADERS) -o $(BONUS_NAME)

bonus: libmlx $(BONUS_NAME)

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME) $(OBJECTS_PATH) $(BONUS_OBJECTS_PATH)

re: fclean all

bre: fclean bonus

.PHONY: all clean fclean re libmlx
