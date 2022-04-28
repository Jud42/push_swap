/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:33:11 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/28 20:31:45 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "libft.h"
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
}	t_list;

void		list_size(t_node *li);
void	print_list(t_node *li);
void	insert_back_list(t_node **li, int nbr);
void	insert_front_node(t_node **li, int nbr);
void	delete_back_list(t_node **li);
void	delete_front_list(t_node **li);
void	clear_list(t_node **li);
/*t_node	swap_a(t_node stack_A);
t_node	swap_b(t_node stack_B);
*/
# endif
