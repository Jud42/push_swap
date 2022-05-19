/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:25:50 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/19 11:50:04 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	five_mng_a(t_list	*a, t_list	*b, int	size)
{
	int	rot;
	int	push;
	int	mid;

	mid = mid_five_sort(a);
	rot = 0;
	push = 0;
	while (size--)
	{
		if (a->head->value < mid)
		{
			push_stack(a, b, B);
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

	mid = mid_five_sort(b);
	rot = 0;
	push = 0;
	while (size--)
	{
		if (b->head->value >= mid)
		{
			push_stack(b, a, A);
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

void	five_mng(t_list	*a, t_list	*b, int	size, int flag)
{
	if (flag == A)
		five_mng_a(a, b, size);
	else
		five_mng_b(a, b, size);
	three_mng_a(a, 3);
	two_mng(a, b, B);
}
