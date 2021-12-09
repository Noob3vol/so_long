NAME = so_long

#Files

SRC_DIR = src/
SRC_FILE = so_long.c \
	   ft_load_map.c \
	   ft_str_utils.c \
	   ft_check_map.c \
	   ft_manage_error.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ_DIR = obj/
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

INC_DIR = inc/
INC_FILE = so_long.h
INC = $(addprefix $(INC_DIR), $(INC_FILE))

#Lib

MLX_DIR = mlx/

#Compilation
CC = clang
WFLAG = -Wall -Wextra -Werror

MLX_FLAGS =  -Imlx -Lmlx -lmlx
#LFLAG = -I./libft/ -L./libft/ -lft
LFLAG = -Lmlx -lmlx -lm -lX11 -lXext -lz -lft
IFLAG = -Imlx -I$(INC_DIR)

FLAG = $(LFLAG) $(MLX_FLAGS)

#$(MLX_FLAGS)

all : makelib $(NAME)

makelib :
	@make -C $(MLX_DIR) > /dev/null

$(NAME) : $(OBJ_DIR) $(OBJ) $(INC)
	$(CC) $(WFLAG) $(IFLAG) -g -o $(NAME) $(OBJ) $(LFLAG)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(IFLAG) $(WFLAG) -g -o $@ -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
