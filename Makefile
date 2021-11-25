NAME = fractol
FRACTOL_OBJ_FILES = $(BUILD_DIR)/main.o\
					$(BUILD_DIR)/mand_hooks.o\
					$(BUILD_DIR)/julia.o\
					$(BUILD_DIR)/julia_hooks.o\
					$(BUILD_DIR)/helper.o\
					$(BUILD_DIR)/mandelbrot.o\
					$(BUILD_DIR)/verify.o\
					$(BUILD_DIR)/paint.o\
					$(BUILD_DIR)/zoom.o
BUILD_DIR = build
VPATH = srcs/libft:srcs/fractol
HEADER_FILES = includes/fractol.h
CFLAGS =
CC = gcc

all: build_dir $(NAME)

$(NAME): $(FRACTOL_OBJ_FILES)
	@echo Assembling Fractol
	@$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ $^ $(CFLAGS)
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
	@ rm -f $(BUILD_DIR)/*.o 

fclean: clean
	@echo Removing Build Directory
	@if [ -d "./$(BUILD_DIR)" ]; then \
	rmdir $(BUILD_DIR); fi
	@echo Removing Fractol
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re