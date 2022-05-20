/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:54:33 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/20 18:52:17 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	two_mng(t_list	*a, t_list	*b, int flag)
{
	if (flag == A)
	{	
		if (a->head->value > a->head->next->value)
			swap_stack(a, A);
	}
	else
	{
		if (b->head->value < b->head->next->value)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
	}
}

void	uno_dos_tres(t_list	*a, t_list	*b, int	size, int	flag)
{
	if (size == 3)
	{
		if (flag == A)
			three_mng_a(a, size);	
		else
			three_mng_b(a, b, size);
	}
	else if (size == 2)
		two_mng(a, b, flag);
	else if (size == 1)
	{
		if (flag == B)
			push_stack(b, a, A);
	}
}

void	for_mng_b(t_list	*a,	t_list	*b, int	size)
{
	int	max;
	
	max = max_value(b, size);
	while (b->head->value != max)
		rotate_stack(b, B);
	push_stack(b, a, A);
	three_mng_b(a, b, size);
}
