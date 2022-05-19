/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/19 11:10:36 by rmamison         ###   ########.fr       */
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
	ft_printf("size => a %d\n", stack_a.size);	
	init_stack(&stack_b);
	print_list(&stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	print_list(&stack_a, &stack_b);
	free(stack_a.head);
	return (0);
}
