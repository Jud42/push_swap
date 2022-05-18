/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:48:44 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/13 17:08:51 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// set the pivot and place it 

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

void	five_sort(t_list	*a, t_list	*b)
{
	int	mid;

	mid = mid_five_sort(a);
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


void	partition_a(t_list	*a, t_list	*b)
{
	int	i;
	int	mid;
	int	mid_mid;

	i       = a->size;
	a->max  = max_value(a);
	a->min  = min_value(a);
	mid     = (a->max + a->min) / 2;
	mid_mid = (a->min + mid) / 2;
	ft_printf("midpoint => %d\n", mid_mid);
	while (i-- > 0)
	{
		if (a->head->value > mid)
			rotate_stack(a, "ra");
		else
		{
			push_stack(a, b, "pb");
			if (b->head->value > mid_mid)
				rotate_stack(b, "rb");

		}
	}
}
/*
void	partition_b(t_list	*b, t_list	*a)
{

}*/
/*void	_kiki(t_list	*a, t_list	*b)
{
	//t_node	*new_a = a->head;
	//t_node	*new_b = b->head;

	if (a->head)
	{
		if (check_need_sort(a))
		{
			part_a(a, b);
			_kiki(a, b);
		}
	//	else if (b->head && check_need_sort(b))
	//		part_a(a, b);		
	}
	ft_printf("finish\n");
