/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:51:26 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/18 19:12:22 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	head_min(t_list	*a, int	max)
{
	if (a->size == 3)
	{
		if (a->top->next == max)
		{
			reverse_rotate(a, A);
			swap_stack(a, A);
		}
	}
	else
	{
		if (a->top->value == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate(a, A);
		}
	}
}

static void	mid_min(t_list	*a, int	max)
{
	if (a->size == 3)
	{
		if (a->last->value == max)
			swap_stack(a, A);
		else
			rotate_stack(a, A);
	}
	else
	{
		swap_stack(a, A);
		if (a->head->next->value == max)
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
		if (a->head->value = max)
			swap_stack(a, A);
		reverse_rotate(a, A);
	}
	else
	{
		if (a->head->value == max)
			swap_stack(a, A);
		rotate_stack(a, A);
		swap_stack(a, A);
		reverse_rotate(a, A);
		swap_stack(a, A);
	}	
}

void	three_mng_a(t_list	*a, int	sz)
{
	int	min;
	int	max;

	min = min_value(a, sz);
	max = max_value(a, sz);
	if (a->head->value == min)
		head_min(a, max);
	else if (a->head->next->value == min)
		mid_min(a, max);
	else if (a->head->next->next->value == min)
		last_min(a, max);
}
