NAME = fractol
FRACTOL_OBJ_FILES = $(BUILD_DIR)/main.o\
					$(BUILD_DIR)/param_handle.o\
					$(BUILD_DIR)/hooks.o\
					$(BUILD_DIR)/julia.o\
					$(BUILD_DIR)/mandelbrot.o
BUILD_DIR = build
VPATH = srcs/libft:srcs/fractol
HEADER_FILES = includes/fractol.h
CFLAGS =
CC = gcc

all: build_dir $(NAME)

$(NAME): $(FRACTOL_OBJ_FILES)
	@echo Compiling Libft and GNL
	@ make -C ./srcs/libft/ bonus > /dev/null
	@echo libft.a compiled
	@echo Assembling Fractol
	@$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ $^ srcs/libft/libft.a $(CFLAGS)
	@echo Fractol has been made!

$(BUILD_DIR)/%.o: %.c
	@$(CC) -I ./includes/ -Imlx -c $(CFLAGS) -o $@ $<

build_dir:
	clear
	@if [ -d "./$(BUILD_DIR)" ]; then \
	echo "Build Directory Already Exists"; \
	else \
	mkdir -p $(BUILD_DIR); \
	fi

clean:
	clear
	@echo Cleaning all object files
	@ make clean -C ./srcs/libft > /dev/null
	@ rm -f $(BUILD_DIR)/*.o 

fclean: clean
	@echo Removing Build Directory
	@ make fclean -C ./srcs/libft > /dev/null
	@if [ -d "./$(BUILD_DIR)" ]; then \
	rmdir $(BUILD_DIR); fi
	@echo Removing Fractol
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re