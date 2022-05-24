/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:25:39 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 19:54:08 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list *stack)
{
	stack->head = NULL;
	stack->last = NULL;
	stack->size = 0;
}

void	init_oper(t_nb_oper	*op)
{
	op->ra = 0;
	op->rb = 0;
	op->pa = 0;
	op->pb = 0;
}

void	init_pivot(t_list *li, int size, t_nb_oper *op)
{
	int		min;
	int		max;

	min = min_value(li, size);
	max = max_value(li, size);
	op->piv = (min + max) / 2;
	op->piv_b = (min + op->piv) / 2;
}
