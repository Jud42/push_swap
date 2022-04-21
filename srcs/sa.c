/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:58:40 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/21 15:26:10 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	swap_a(t_stack *stack)
{
	int	a;

	if (stack->size < 2)
		return ;
	a = stack->stack_A[0];
	stack->stack_A[0] = stack->stack_A[1];
	stack->stack_A[1] = a;
}

void	swap_b(t_stack *stack)
{
	//int	a;
    int	i;

	i = -1;
	stack->stack_B = (int *)malloc(sizeof(int) * (stack->size));
	if(!stack->stack_B)
		ft_printf("allocation failed\n");
	while (++i < stack->size)
		stack->stack_B[i] = stack->stack_A[i];
	if (!stack->stack_B || !stack->stack_B[1])
		return ;
	/*a = stack->stack_B[0];
	stack->stack_B[0] = stack->stack_B[1];
	stack->stack_B[1] = a;*/
}

void	swap_a_b(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
