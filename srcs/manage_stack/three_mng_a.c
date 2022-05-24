/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:51:26 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 19:36:31 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	head_min(t_list *a, int max)
{
	if (a->size == 3)
	{
		if (a->head->next->pos == max)
		{
			reverse_rotate(a, A);
			swap_stack(a, A);
		}
	}
	else
	{
		if (a->head->next->pos == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate(a, A);
		}
	}
}

static void	mid_min(t_list *a, int max)
{
	if (a->size == 3)
	{
		if (a->last->pos == max)
			swap_stack(a, A);
		else
			rotate_stack(a, A);
	}
	else
	{
		swap_stack(a, A);
		if (a->head->next->pos == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate(a, A);
		}
	}
}

static void	last_min(t_list	*a, int max)
{
	if (a->size == 3)
	{
		if (a->head->pos == max)
			swap_stack(a, A);
		reverse_rotate(a, A);
	}
	else
	{
		if (a->head->pos == max)
			swap_stack(a, A);
		rotate_stack(a, A);
		swap_stack(a, A);
		reverse_rotate(a, A);
		swap_stack(a, A);
	}	
}

void	three_mng_a(t_list *a, int size)
{
	int	min;
	int	max;

	min = min_value(a, size);
	max = max_value(a, size);
	if (a->head->pos == min)
		head_min(a, max);
	else if (a->head->next->pos == min)
		mid_min(a, max);
	else if (a->head->next->next->pos == min)
		last_min(a, max);
}
