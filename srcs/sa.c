/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:58:40 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/26 14:30:54 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
List	swap_a(List stack_A)
{
	int	a;
	ListElement *elem;
	ft_printf("stackAsize %d\n", stack_A->size);	
	if ((empty_list(stack_A)) || stack_A->size == 1)
		return (0);
	a = stack_A->value;
	elem = stack_A->next;
	stack_A->value = elem->value;
	elem->value = a;
	stack_A->next = elem;
	elem = NULL;
	return (stack_A);
}

List	swap_b(List stack_B)
{
	int	a;
	ListElement *elem;
	
	if (empty_list(stack_B) || stack_B->size == 1)
		return (0);
	a = stack_B->value;
	elem = stack_B->next;
	stack_B->value = elem->value;
	elem->value = a;
	stack_B->next = elem;
	elem = NULL;
	return (stack_B);
}

/*void	swap_a_b(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	push_a(List stack_A, List stack_B)
{
	if (empty_list(stack_B))
		return ;
	stack_A = insert_front_list(stack_A, stack_B->value);
	stack_B = delete_front_list(stack_B);
}

void	push_b(List stack_B, List stack_A)
{
	if (empty_list(stack_A))
		return ;
	stack_B = insert_front_list(stack_B, stack_A->value);
	stack_A = delete_front_list(stack_A);
}
*/
