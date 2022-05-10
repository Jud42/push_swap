
NAME		= push_swap
LIB_PRINTF_DIR		= ./libft/ft_printf
SRCS	= mainlist.c	utiList.c	sa.c	sort_utils.c
DIR_S	= srcs
DIR_O	= temp
RM 	= rm -rf
INCLUDE	= -I./include -I./libft -I./libft/ft_printf/
LIB_A	= -L$(LIB_PRINTF_DIR) $(LIB_PRINTF_DIR)/libft_printf.a
CFLAGS	= -g -Wall -Wextra -Werror -fsanitize=address
DFLAGS	= 
CC	= clang

SR	=	$(addprefix $(DIR_S)/, $(SRCS))
OB	=	$(addprefix $(DIR_O)/, $(SRCS:%.c=%.o))


$(DIR_O)/%.o : $(DIR_S)/%.c
	mkdir -p temp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(DFLAGS)

$(NAME) : $(OB)
	make -C $(LIB_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OB) $(INCLUDE) $(LIB_A) $(FRAMEWORK) -o $@

all :	$(NAME)

clean	:
		$(RM) $(DIR_O)
		make clean -C $(LIB_PRINTF_DIR)

fclean	: clean 
	$(RM) $(NAME)
	make fclean -C $(LIB_PRINTF_DIR)

re	: fclean $(NAME)

.PHONY:	all clean fclean re

