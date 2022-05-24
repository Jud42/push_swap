/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:52:15 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/20 19:16:01 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  small_nbr(t_list    *a, t_list  *b, int size)
{
	if (size <= 3)
	{
		uno_dos_tres(a, b, size, B);
		return (0);
	}
	else if (size == 5)
	{
		five_mng(a, b, 5, B);
	         return (0);
 	}
 	return (1);
}
/*-----------------------------------------------------------*/

static void	part_b(t_list	*a, t_list	*b, t_nb_oper	*op)
{
	if (b->head->value <= op->piv_b)
	{
		rotate_stack(b, B);
		op->rb++;
	}
	else
	{	
		push_stack(b, a, A);
		op->pa++;
		if (a->head->value <= op->piv)
		{
			rotate_stack(a, A);
			op->ra++;
		}
	}
}

static void	reversing_ra(t_list	*a, t_list	*b, t_nb_oper	*op)
{
	int	i;
	int	j;
	
	i = op->rb;
	j = op->ra - i;
	while (i--)
		reverse_rotate_a_b(a, b);
	while (j--)
		reverse_rotate(a, A);
}

static void	reversing_rb(t_list	*a, t_list	*b, t_nb_oper	*op)
{
	int	i;
	int	j;
	
	i = op->ra;
	j = op->rb - i;
	while (i--)
		reverse_rotate_a_b(a, b);
	while (j--)
		reverse_rotate(b, B);
}

void	sort_b(t_list	*a, t_list	*b, int	size, int	*count)
{
	t_nb_oper	op;
	int	i;

	(*count)++;
	if (!small_nbr(a, b, size))
		return ;
	init_oper(&op);
	init_pivot(b, size, &op);
	i = size;
	while (i--)
		part_b(a, b, &op);
	sort_a(a, b, op.pa - op.ra, count);
	if (op.ra > op.rb)
		reversing_ra(a, b, &op);
	else
		reversing_rb(a, b, &op);
	sort_a(a, b, op.ra, count);
	sort_b(a, b, op.rb, count);
	print_list(a, b);
}
