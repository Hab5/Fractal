.PHONY: all, $(NAME), clean, fclean, re

NAME = fractol

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

cc = gcc
C_FLAGS = -Wall -Wextra -Werror -g
FRAM = -I /usr/include -lmlx -framework OpenGL -framework AppKit -g

OBJ_PATH = ./obj/
LFT_PATH = ./libft/
INC_PATH = ./includes/
SRC_PATH = ./srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fractol.h
SRC_NAME = mandelbrot.c julia.c burningship.c tricorn.c tools.c hook.c fractol.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		@echo
		@make -C $(LFT_PATH)
		@$(CC) -o $(NAME) $(FRAM) -L $(LFT_PATH) -lft $^ -o $@
		@echo "\033[32mFractol ready.\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<
		@echo -n =

clean:
		@make -C $(LFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "\033[32mDeleting [./obj] directory.\033[0m"

fclean: clean
		@make -C $(LFT_PATH) fclean
		@rm -f $(NAME)
		@echo "\x1b[31mSUCESSFULLY CLEANED FRACTOL\x1b[31m"

re: fclean all
