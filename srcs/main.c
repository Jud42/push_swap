/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:35:13 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 20:43:41 by rmamison         ###   ########.fr       */
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
	replace_data(&stack_a);
	init_stack(&stack_b);
	push_swap(&stack_a, &stack_b);
	clear_list(&stack_a);
	return (0);
}
