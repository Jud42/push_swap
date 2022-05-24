/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:25:39 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/20 17:12:20 by rmamison         ###   ########.fr       */
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
}

void	init_pivot(t_list	*li, int	size, t_nb_oper	*op)
{
	long	min_l;
	long	max_l;

	min_l = min_value(li, size);
	max_l = max_value(li, size);
	op->piv = (min_l + max_l) / 2;
	op->piv_b = (min_l + op->piv) / 2;
}
