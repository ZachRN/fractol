NAME = fractol
FRACTOL_OBJ_FILES = $(BUILD_DIR)/main.o\
					$(BUILD_DIR)/mand_hooks.o\
					$(BUILD_DIR)/julia.o\
					$(BUILD_DIR)/julia_hooks.o\
					$(BUILD_DIR)/julia_mouse_hook.o\
					$(BUILD_DIR)/helper.o\
					$(BUILD_DIR)/mandelbrot.o\
					$(BUILD_DIR)/verify.o\
					$(BUILD_DIR)/paint.o\
					$(BUILD_DIR)/zoom.o
BUILD_DIR = build
MLX_MADE = libmlx.dylib
VPATH = srcs/libft:srcs/fractol
HEADER_FILES = -I ./includes/ -I ./srcs/ft_printf/includes/
CFLAGS = -Wall -Werror -Wextra
ft_printf = ./srcs/ft_printf/libftprintf.a
CC = gcc

all: build_dir $(MLX_MADE) $(NAME)

$(NAME): $(FRACTOL_OBJ_FILES)
	@echo Assembling Fractol
	@ make -C ./srcs/ft_printf/ > /dev/null
	@$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ $^ $(CFLAGS) $(ft_printf)
	@echo Fractol has been made!

$(BUILD_DIR)/%.o: %.c
	@$(CC) $(HEADER_FILES) -Imlx -c $(CFLAGS) -o $@ $<

build_dir:
	clear
	@if [ -d "./$(BUILD_DIR)" ]; then \
	echo "Build Directory Already Exists"; \
	else \
	mkdir -p $(BUILD_DIR); \
	fi

$(MLX_MADE):
	@echo Generating MLX
	@make -C ./mlx > /dev/null
	@cp ./mlx/$(MLX_MADE) $(MLX_MADE)

clean:
	clear
	@echo Cleaning all object files
	@ make clean -C ./srcs/ft_printf
	@ rm -f $(BUILD_DIR)/*.o 
	@echo Removing Build Directory
	@if [ -d "./$(BUILD_DIR)" ]; then \
	rmdir $(BUILD_DIR); fi
	@ make clean -C ./mlx > /dev/null

fclean: clean
	@echo Removing Fractol
	@ make fclean -C ./srcs/ft_printf
	@ rm -f $(NAME)
	@ rm -f $(MLX_MADE)

bonus: all

re: fclean all

.PHONY: all clean fclean re