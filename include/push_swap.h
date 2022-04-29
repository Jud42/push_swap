/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:33:11 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/29 13:52:53 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define false 0
# define true 1

typedef struct s_node{
	int	value;
	struct s_node *next;
	struct	s_node	*prev;
	int	size;
}	t_node; 

typedef	struct	s_list{
	struct	s_node	*head;
	stuct	s_node	*last;
}	t_list;

void		list_size(t_list *li);
void	print_list(t_list *li);
void	insert_back_list(t_list	*li, int nbr);
void	insert_front_list(t_list *li, int nbr);
void	delete_back_list(t_list *li);
void	delete_front_list(t_list *li);
void	clear_list(t_list *li);
void	swap_stack(t_list *li, char *s);
void	swap_a_b(t_list *a, t_list *b);
void	push_stack(t_list *li_a, t_list *li_b, char *s);
# endif
