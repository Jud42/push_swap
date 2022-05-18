/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:25:50 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/18 19:33:21 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	five_mng_a(t_list	*a, t_list	*b, int	size)
{
	int	rot;
	int	push;
	int	mid;

	mid = mid_five_sort(a, size)
	rot = 0;
	push = 0;
	while (size--)
	{
		if (a->head->value < mid)
		{
			push_swap(a, b, B);
			push++;
		}
		else
		{	
			rotate_stack(a, A);
			rot++;
		}
		if (push == 2)
			break ;
	}
	while (rot--)
		reverse_rotate(a, A);	
}

static void	five_mng_b(t_list	*a, t_list	*b, int	size)
{
	int	rot;
	int	push;
	int	mid;

	mid = mid_five_sort(b, size)
	rot = 0;
	push = 0;
	while (size--)
	{
		if (b->head->value >= mid)
		{
			push_swap(b, a, A);
			push++;
		}
		else
		{	
			rotate_stack(b, B);
			rot++;
		}
		if (push == 3)
			break ;
	}
	while (rot--)
		reverse_rotate(b, B);	
}

void	five_mng(t_list	*a, t_list	*b, int	sz, int flag)
{
	if (flag == A)
		five_mng_a(a, b, sz);
	else
		five_mng_b(a, b, sz);
	three_mng(a, 3);
	two_mng(a, b, B);
}
