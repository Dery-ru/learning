NAME = push_swap

HEADER = ./includes/push_swap.h ./libft/includes/libft.h

LIBRARY = -lft -L$(LIBFT_PATH)

LIBFT = $(LIBFT_PATH)libft.a

LIBFT_PATH = ./libft/

LIST =	$(wildcard ./sources/*.c)

OBJ = $(LIST:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(LIBFT) : 
	@make -sC $(LIBFT_PATH)

$(NAME) : $(LIBFT) $(OBJ) $(HEADER)
	gcc $(FLAGS) $(LIBRARY) $(INC) $(OBJ) -o $@

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
