# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 00:03:07 by yusman            #+#    #+#              #
#    Updated: 2023/05/21 23:53:29 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC		= moves/pa.c moves/pb.c moves/ra.c moves/rra.c\
moves/sb.c moves/sa.c moves/rr.c moves/rb.c moves/rrb.c\
parsing/checkarg.c parsing/checksort.c parsing/utils.c \
sort/numbers.c sort/sort_smallnum.c sort/utils.c push_swap.c \
sort/sort_large.c sort/stack_set_utils.c sort/stack_set_utils2.c \
sort/stack_set.c sort/stack_sort_utils.c sort/num_utils.c \
sort/quick_sort.c sort/stack_divide_conquer_utils.c \
sort/stack_divide_conquer.c sort/stack_insertsort_a.c \
sort/stack_insertsort_b.c


OBJ		= $(SRC:.c=.o)

LIBFT	= ./libft/libft.a

FT_PRINTF = ./ft_printf/libftprintf.a

CFLAGS	= -Wall -Wextra -Werror -g

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ)
		make -sC ./ft_printf
		 gcc -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
		make -C libft all

clean:
		rm -f $(OBJ)
		make clean -sC ./ft_printf
		make -C libft fclean

fclean: clean
		make fclean -sC ./ft_printf
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
