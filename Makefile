NAME =	push_swap

SRC	=	push_swap.c utils.c instr_push_swap.c \
        instr_rotate.c instr_rev_rotate.c \
        instr_max_min.c instr_calc_copy.c \
        instr_pos_comb.c instr_lis.c \
        instr_sort.c instr_free.c

LIBFT	=	libft/libft.a
OBJ		=	$(SRC:.c=.o)
CC		=	cc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
	make clean -C libft
	${RM} $(OBJ)

fclean: 	clean
	make fclean -C libft
	${RM} $(NAME) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re
