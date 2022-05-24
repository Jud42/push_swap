/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:54:33 by rmamison          #+#    #+#             */
/*   Updated: 2022/05/24 19:35:30 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_mng(t_list *a, t_list *b, int flag)
{
	if (flag == A)
	{	
		if (a->head->pos > a->head->next->pos)
			swap_stack(a, A);
	}
	else
	{
		if (b->head->pos < b->head->next->pos)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
	}
}

void	uno_dos_tres(t_list *a, t_list *b, int size, int flag)
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

int	small_nbr(t_list *a, t_list *b, int size, int flag)
{
	if (size <= 3)
	{
		uno_dos_tres(a, b, size, flag);
		return (0);
	}
	else if (size == 5)
	{
		five_mng(a, b, size, flag);
		return (0);
	}
	return (1);
}
