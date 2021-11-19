NAME = libftprintf.a

LIST =	./sourses/basic_fts.c		./sourses/flag_parser.c	./sourses/ft_printf.c\
		./sourses/fts_num_len.c	./sourses/print_c.c		./sourses/print_int.c\
		./sourses/print_pers.c	./sourses/type_printer.c ./sourses/print_str.c\
		./sourses/print_uns_int.c	./sourses/print_hex.c	./sourses/print_pointer.c\

OBJ = $(LIST:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re