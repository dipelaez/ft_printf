NAME = libftprintf.a

CC = clang

CCLIB = ar rcs

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f 

INCLUDE = libft/

SRC = ft_printf.c \
	ft_list.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all:	$(OBJ)
	make -C ./libft/
	cp libft/libft.a $(NAME)
	$(CCLIB) $(NAME) $(OBJ) 
main: all
	$(CC) $(CFLAGS) main.c -L . -lftprintf -I $(INCLUDE) -o a.out

clean:
	$(RM) $(OBJ) 
	make clean -C ./libft/

fclean:	clean
	$(RM) a.out $(NAME)
	make fclean -C ./libft/

re:	fclean all

.PHONY:        all clean fclean re
