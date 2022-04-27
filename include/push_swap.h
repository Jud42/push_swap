/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:33:11 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/27 19:17:07 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define false 0
# define true 1

/*typedef struct s_stack{

	int	*stack_A;
	int	*stack_B;
	int	size;
}	t_stack;*/

typedef struct s_node{
	int	value;
	struct s_node *next;
	int	size;
}	t_node;

void		list_size(t_node *li);
void	print_list(t_node *li);
void	insert_back_list(t_node **li, int nbr);
/*t_node	insert_front_node(t_node li, int nbr);
t_node	delete_back_list(t_node li);
t_node	delete_front_node(t_node li);
t_node	clear_list(t_node li);
t_node	swap_a(t_node stack_A);
t_node	swap_b(t_node stack_B);
*/
# endif
