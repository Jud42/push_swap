/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:33:11 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/21 22:09:14 by rmamison         ###   ########.fr       */
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

typedef struct ListElement{
	int	value;
	struct ListElement *next;
}ListElement, *List;

int		empty_list(List li);
int		list_size(List li);
void	print_list(List li);
List	insert_back_list(List li, int nbr);
List	insert_front_list(List li, int nbr);
List	delete_back_list(List li);
List	delete_front_list(List li);
List	clear_list(List li);
/*void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
*/

# endif
