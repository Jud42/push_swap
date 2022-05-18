/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:48:44 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/18 21:43:19 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// set the pivot and place it 
/*
void	three_sort(t_list	*li)
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
			rotate_stack(li, "ra");
		if (h > n && h < l)
			swap_stack(li, "sa");
		if (l < n && n > h)
			reverse_rotate(li, "rra");
	}
}
*/
void	five_sort(t_list	*a, t_list	*b)
{
	int	mid;

	mid = mid_five_sort(a, a->size);
	while (1)
	{	
		if (a->head->value < mid)
			push_stack(a, b, "pa");
		else
			rotate_stack(a, "ra");
		if (b->size == 2)
			break ;
	}
	three_sort(a);
	if (b->head->value < b->head->next->value)
		swap_stack(b, "sb");
	while (b->head)
		push_stack(b, a, "pb");
}



