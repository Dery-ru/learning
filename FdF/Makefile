NAME = fdf

HEADER = ./includes/fdf.h ./libft/includes/libft.h

LIBRARY = -lft -L$(LIBFT_PATH)

LIBFT = $(LIBFT_PATH)libft.a

LIBFT_PATH = ./libft/

LIST =	./sources/draw.c ./sources/fdf_utils.c ./sources/ft_init.c ./sources/main.c \
		./sources/map_check.c ./sources/rotate_and_zoom.c

OBJ = $(LIST:.c=.o)

FLAGS = -Wall -Wextra -Werror

INC = -lmlx -I /usr/local/include

FRMW = -framework OpenGL -framework AppKit

all: $(NAME)

$(LIBFT) : 
	@make -sC $(LIBFT_PATH)

$(NAME) : $(LIBFT) $(OBJ) $(HEADER)
	gcc $(FLAGS) $(LIBRARY) $(FRMW) $(INC) $(OBJ) -o $@



%.o : %.c $(INC)
	gcc -c $(FLAGS) $< -o $@

clean:
	@make -C libft/ clean
	rm -rf $(OBJ)

fclean:	clean
	@make -C libft/ fclean
	rm -rf $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
