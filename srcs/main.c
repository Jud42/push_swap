/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/19 19:18:59 by rmamison         ###   ########.fr       */
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
	parse_in(argc, argv, &stack_a);
	ft_printf("size => a %d\n", stack_a.size);	
	init_stack(&stack_b);
	print_list(&stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	print_list(&stack_a, &stack_b);
	clear_list(&stack_a);
	print_list(&stack_a, &stack_b);
	ft_printf("size a => %d, size b => %d\n", stack_a.size, stack_b.size);
	return (0);
}
