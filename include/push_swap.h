/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:33:11 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/25 15:52:57 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define FALSE 0
# define TRUE 1
# define A 2
# define B 3
# define DUP 4
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node{
	int				value;
	int				pos;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list{
	int				size;
	struct s_node	*head;
	struct s_node	*last;
}	t_list;

typedef struct s_nb_oper{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
	int	piv;
	int	piv_b;
}	t_nb_oper;

void	error_msg(void);
void	parse_in(int argc, char **argv, t_list *stack);
int		atoi_pswap(const char	*str);

void	init_stack(t_list *stack);
void	init_oper(t_nb_oper *op);
void	init_pivot(t_list *li, int size, t_nb_oper *op);

int		list_size(t_list *li);
t_node	*last_node(t_list *li);
void	insert_back_list(t_list	*li, int nbr);
void	insert_front_list(t_list *li, int nbr);
void	delete_back_list(t_list *li);
void	delete_front_list(t_list *li);
void	clear_list(t_list *li);

void	swap_stack(t_list *li, int flag);
void	swap_a_b(t_list *a, t_list *b);
void	push_stack(t_list *from, t_list *to, int flag);
void	rotate_stack(t_list *li, int flag);
void	rotate_a_b(t_list *a, t_list *b);
void	reverse_rotate(t_list *li, int flag);
void	reverse_rotate_a_b(t_list *a, t_list *b);

int		max_value(t_list *li, int size);
int		min_value(t_list *li, int size);
int		mid_five_sort(t_list *li);

int		check_need_sort(t_list *li);
void	replace_data(t_list	*li);

void	easy_sort(t_list *a, t_list *b);
void	sort_a(t_list *a, t_list *b, int size, int *count);
void	sort_b(t_list *a, t_list *b, int size, int *count);
void	push_swap(t_list *a, t_list *b);

void	two_mng(t_list *a, t_list *b, int flag);
void	three_mng_a(t_list *a, int size);
void	three_mng_b(t_list *a, t_list *b, int size);
void	uno_dos_tres(t_list *a, t_list *b, int size, int flag);
void	five_mng(t_list *a, t_list *b, int size, int flag);
int		small_nbr(t_list *a, t_list *b, int size, int flag);
#endif
