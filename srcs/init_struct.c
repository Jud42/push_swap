/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:25:39 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/19 22:14:43 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list *stack)
{
	stack->head = NULL;
   	stack->last = NULL;
	stack->size = 0;
	stack->max  = 0;
	stack->min  = 0;
	stack->mid  = 0;
}

void	init_oper(t_nb_oper	*op)
{
	op->ra = 0;
	op->rb = 0;
	op->pa = 0;
	op->pb = 0;
	op->piv = 0;
	op->piv_b = 0;
}

void	init_pivot(t_list	*li, int	size, t_nb_oper	*op)
{
	int	min;
	int	max;

	min = min_value(li, size);
	max = max_value(li, size);
	op->piv = (min + max) / 2;
	op->piv_b = (op->piv + min) / 2;
}
