/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:48:44 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 20:05:08 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	for_sort(t_list	*a,	t_list	*b)
{
	int	min;
	int	max;
	int	i;

	i = -1;
	min = min_value(a, a->size);
	max = max_value(a, a->size);
	while (++i < a->size)
	{
		if (a->head->pos == min || a->head->pos == max)
		{
			push_stack(a, b, B);
			break ;
		}
		else
			reverse_rotate(a, A);
	}
	three_mng_a(a, a->size);
	push_stack(b, a, A);
	if (a->head->pos == max)
		rotate_stack(a, A);
}
/*--------------------------------------*/

static	void	five_sort(t_list	*a, t_list	*b)
{
	int	mid;

	mid = mid_five_sort(a);
	while (1)
	{	
		if (a->head->value < mid)
			push_stack(a, b, B);
		else
			rotate_stack(a, A);
		if (b->size == 2)
			break ;
	}
	three_mng_a(a, a->size);
	if (b->head->value < b->head->next->value)
		swap_stack(b, B);
	while (b->head)
		push_stack(b, a, A);
}
/*-----------------------------------------*/

void	easy_sort(t_list	*a, t_list	*b)
{
	if (a->size <= 3)
		uno_dos_tres(a, b, a->size, A);
	else if (a->size == 4)
		for_sort(a, b);
	else if (a->size == 5)
		five_sort(a, b);
}
