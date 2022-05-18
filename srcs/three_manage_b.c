/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:51:26 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/18 13:23:40 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	head_min(t_list	*b, int	max)
{
	if (b->size == 3)
	{
		rotate_stack(b, B);
		if (b->top->next == max)
			swap_stack(b, B);
	}
	else
	{
		swap_stack(b, B);
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate(b, B);
		if (b->top->next->value == max)
			swap_stack(b, B);
	}
}

static void	mid_min(t_list	*b, int	max)
{
	if (b->size == 3)
	{
		reverse_rotate(b, B);
		if (b->head->next == max)
			swap_stack(b, B);
	}
	else
	{
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate(b, B);a
		if (b->head->next->value == max)
			swap_stack(b, B);
	}
}

static void	last_min(t_list	*b, int max)
{
	if (b->size == 3)
		if (b->head->next = max)
			swap_stack(b, B);
}

void	three_mng_b(t_list	*b, int	sz)
{
	int	min;
	int	max;

	min = min_value(b, sz);
	max = max_value(b, sz);
	if (b->head->value == min)
		head_min(b, max);
	else if (b->head->next->value == min)
		mid_min(b, max);
	else if (b->head->next->next->value == min)
		last_min(b, max);
	push_swap(b, a, A);
	push_swap(b, a, A);
	push_swap(b, a, A);
}
