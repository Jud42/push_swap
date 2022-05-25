# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 13:47:16 by rmamison          #+#    #+#              #
#    Updated: 2022/05/25 13:52:00 by rmamison         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

LIB_PRINTF_DIR		= ./libft/ft_printf

SRCS	= main.c push_swap.c \
	manage_stack/five_mng.c \
	manage_stack/mng_until_five.c \
	manage_stack/three_mng_a.c manage_stack/three_mng_b.c \
	operation42/rotate_reverse.c operation42/swap_push.c	\
	parse_init/init_struct.c parse_init/parse_input.c \
	sort_algo/sort_until_five.c \
	sort_algo/sort_stack_a.c sort_algo/sort_stack_b.c \
	utils/find_middle.c \
	utils/replace.c	utils/utilist.c	\
	utils/atoi_pswap.c	\

DIR_S	= srcs
DIR_O 	= temp

TEMP_DIR = temp	temp/manage_stack \
	temp/operation42 \
	temp/parse_init \
	temp/sort_algo \
	temp/utils \

RM 	= rm -rf
INCLUDE	= -I./include -I./libft -I./libft/ft_printf/
LIB_A	= -L$(LIB_PRINTF_DIR) $(LIB_PRINTF_DIR)/libft_printf.a
CFLAGS	= -g -Wall -Wextra -Werror -fsanitize=address
CC	= clang
SR	=	$(addprefix $(DIR_S)/, $(SRCS))
OB	=	$(addprefix $(DIR_O)/, $(SRCS:%.c=%.o))

$(DIR_O)/%.o : $(DIR_S)/%.c
	@mkdir -p $(TEMP_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OB)
	@make -C $(LIB_PRINTF_DIR)
	@$(CC) $(CFLAGS) $(OB) $(INCLUDE) $(LIB_A) -o $@

all :	$(NAME)

clean	:
	@$(RM) $(DIR_O)
	@make clean -C $(LIB_PRINTF_DIR)

fclean	: clean 
	@$(RM) $(NAME)
	@make fclean -C $(LIB_PRINTF_DIR)

re	: fclean $(NAME)

.PHONY:	all clean fclean re 
