NAME =	push_swap

SRC	=	push_swap.c utils.c instrcutionPushSwap.c \
        instructionRotate.c instructionRevRotate.c \
        instructionMaxnmin.c instructionCalculateNCopy.c \
        instructionPostionNCombination.c instructionLIS.c \
        instructionSort.c instructionFree.c

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
