/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:33:11 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/13 17:09:00 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define false 0
# define true 1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node{
	int	value;
	struct s_node *next;
	struct	s_node	*prev;
}	t_node; 

typedef	struct	s_list{
	int	max;
	int	min;
	int	mid;
	int	size;
	struct	s_node	*head;
	struct	s_node	*last;
}	t_list;

typedef	struct	s_nb_oper{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_nb_oper;

void	init_stack(t_list *stack);
void	parse_in(char **argv, t_list *stack);
void	last_node(t_list *li);
int		list_size(t_list *li);
void	print_list(t_list *a, t_list *b);
void	insert_back_list(t_list	*li, int nbr);
void	insert_front_list(t_list *li, int nbr);
void	delete_back_list(t_list *li);
void	delete_front_list(t_list *li);
void	clear_list(t_list *li);
void	swap_stack(t_list *li, char *s);
void	swap_a_b(t_list *a, t_list *b);
void	push_stack(t_list *li_a, t_list *li_b, char *s);
void	rotate_stack(t_list *li, char *s);
void	rotate_a_b(t_list *a, t_list *b, char *s);
void	reverse_rotate(t_list *li, char *s);
void	rotate_a_b(t_list *a, t_list *b, char *s);
void	reverse_rotate_a_b(t_list *a, t_list *b, char *s);
int	max_value(t_list *li);
int	min_value(t_list *li);
int	middle_list(t_list *li);
int	mid_five_sort(t_list *li);
void	three_sort(t_list *li);
void	five_sort(t_list *a, t_list *b);
void	big_sort(t_list *a, t_list *b);
void	partition_a(t_list *a, t_list *b);
int	check_need_sort(t_list *li);
void	push_swap(t_list *a, t_list *b);

# endif
