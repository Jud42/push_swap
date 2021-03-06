/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:51:26 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 19:37:42 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	head_min(t_list *b, int max)
{
	if (b->size == 3)
	{
		rotate_stack(b, B);
		if (b->head->next->pos == max)
			swap_stack(b, B);
	}
	else
	{
		swap_stack(b, B);
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate(b, B);
		if (b->head->next->pos == max)
			swap_stack(b, B);
	}
}

static void	mid_min(t_list *b, int max)
{
	if (b->size == 3)
	{
		reverse_rotate(b, B);
		if (b->head->next->pos == max)
			swap_stack(b, B);
	}
	else
	{
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate(b, B);
		if (b->head->next->pos == max)
			swap_stack(b, B);
	}
}

static void	last_min(t_list	*b, int max)
{
	if (b->head->next->pos == max)
		swap_stack(b, B);
}

void	three_mng_b(t_list *a, t_list *b, int size)
{
	int	min_l;
	int	max_l;

	min_l = min_value(b, size);
	max_l = max_value(b, size);
	if (b->head->pos == min_l)
		head_min(b, max_l);
	else if (b->head->next->pos == min_l)
		mid_min(b, max_l);
	else if (b->head->next->next->pos == min_l)
		last_min(b, max_l);
	push_stack(b, a, A);
	push_stack(b, a, A);
	push_stack(b, a, A);
}
