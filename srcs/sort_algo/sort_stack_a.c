/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:52:15 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/25 16:02:40 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	part_a(t_list	*a, t_list	*b, t_nb_oper	*op)
{
	if (a->head->pos > op->piv)
	{
		rotate_stack(a, A);
		op->ra++;
	}	
	else
	{
		push_stack(a, b, B);
		op->pb++;
		if (b->head->pos > op->piv_b)
		{
			rotate_stack(b, B);
			op->rb++;
		}
	}
}
/*-----------------*/

static void	reversing_a(t_list	*a, t_list	*b, t_nb_oper	*op, int	*count)
{
	int	i;
	int	j;

	i = op->rb;
	j = op->ra - i;
	if ((*count) > 0)
	{
		while (i--)
			reverse_rotate_a_b(a, b);
		while (j--)
			reverse_rotate(a, A);
	}
	else
	{
		while (i--)
			reverse_rotate(b, B);
	}
}
/*-------------------------*/

static void	reversing_b(t_list	*a, t_list	*b, t_nb_oper	*op, int	*count)
{
	int	i;
	int	j;

	i = op->ra;
	j = op->rb - i;
	if ((*count) > 0)
	{
		while (i--)
			reverse_rotate_a_b(a, b);
		while (j--)
			reverse_rotate(b, B);
	}
	else
	{
		i = op->rb;
		while (i--)
			reverse_rotate(b, B);
	}
}
/*-------------------------------*/

void	sort_a(t_list *a, t_list *b, int size, int *count)
{
	t_nb_oper	op;
	int			i;

	if (!small_nbr(a, b, size, A))
		return ;
	init_oper(&op);
	init_pivot(a, size, &op);
	i = size;
	while (i--)
		part_a(a, b, &op);
	if (op.ra > op.rb)
		reversing_a(a, b, &op, count);
	else
		reversing_b(a, b, &op, count);
	sort_a(a, b, op.ra, count);
	sort_b(a, b, op.rb, count);
	sort_b(a, b, op.pb - op.rb, count);
}
