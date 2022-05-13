/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/13 17:08:54 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{	
	t_list	stack_a;
	t_list	stack_b;
	
	if (argc == 1)
		exit(1);
	init_stack(&stack_a);
	parse_in(argv, &stack_a);	
//	if (stack_a.size == 3)
//		mini_sort(&stack_a);
	init_stack(&stack_b);
	print_list(&stack_a, &stack_b);
	reverse_rotate(&stack_a, "test");
	print_list(&stack_a, &stack_b);
	swap_stack(&stack_a, " swap");
	print_list(&stack_a, &stack_b);
	push_stack(&stack_a, &stack_b, "push");
	print_list(&stack_a, &stack_b);
//	_quickSort(stack_a.head, stack_a.last, &stack_a);
//	_kiki(&stack_a, &stack_b);
	return (0);
}
