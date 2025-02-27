NAME		=	push_swap

NAME_BONUS	=	checker

SRC			=	push_swap.c utils.c instrcution_push_swap.c \
				instruction_rotate.c instruction_rev_rotate.c \
				instruction_maxnmin.c instruction_calculate_n_copy.c \
				instruction_postion_n_combination.c instrction_LIS.c \
				instruction_sort.c instruction_free.c\

SRC_BONUS	=	checker.c check_utils.c check_instruction_one.c\
				check_instruction_two.c check_instruction_three.c\
				check_free.c\

LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)

re:			fclean bonus

bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)


.PHONY:		all clean fclean re
