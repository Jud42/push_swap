/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:48:44 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/19 21:48:48 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// set the pivot and place it 

static	void	three_sort(t_list	*li)
{
	int	h;
	int	n;
	int	l;

	while (check_need_sort(li))
	{
		h = li->head->value;
		n = li->head->next->value;
		l = li->last->value;
		if (h > n && h > l)
			rotate_stack(li, A);
		if (h > n && h < l)
			swap_stack(li, A);
		if (l < n && n > h)
			reverse_rotate(li, A);
	}
}

static	void	for_sort(t_list	*a,	t_list	*b)
{
	int	min;
	int	max;
	int	i;

	i = -1;
	min	= min_value(a, a->size);
	max = max_value(a, a->size);
	while (++i < a->size)
	{
		if (a->head->value == min || a->head->value == max)
		 {
		 	push_stack(a, b, B);
			break ;
		 }
		else
			reverse_rotate(a, A);	
	}
	three_sort(a);
	push_stack(b, a, A);
	if (a->head->value == max)
		rotate_stack(a, A);
}

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
	three_sort(a);
	if (b->head->value < b->head->next->value)
		swap_stack(b, B);
	while (b->head)
		push_stack(b, a, A);
}

void	little_sort(t_list	*a, t_list	*b)
{
	if (a->size == 2)
		swap_stack(a, A);
	else if (a->size == 3)
		three_sort(a);
	else if (a->size == 4)
		for_sort(a, b);
	else if (a->size == 5)
		five_sort(a, b);

}
